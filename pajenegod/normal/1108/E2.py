import sys
range = xrange
input = raw_input

# a very nice implementation of a minimum segment tree with 
# some inspiration taken from https://codeforces.com/blog/entry/18051
# this implementation should be able to be modified to do pretty
# much anything one would want to do with segment trees apart from
# persistance.
# note that especially in python this implementation is much much better
# than most other approches because how slow python can be with function
# calls. /pajenegod

# currently it allows for two operations, both running in o(log n),
# 'add(l,r,value)' adds value to [l,r)
# 'find_min(l,r)' finds the index with the smallest value

big = 10**9

class super_seg:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n: m *= 2
        
        self.n = n
        self.m = m
        self.data = [big]*(2*m)
        for i in range(n):
            self.data[i+m] = data[i]
        for i in reversed(range(m)):
            self.data[i] = min(self.data[2*i], self.data[2*i+1])
        self.query = [0]*(2*m)
    
    # push the query on seg_ind to its children
    def push(self,seg_ind):
        # let the children know of the queries
        q = self.query[seg_ind]

        self.query[2*seg_ind]   += q
        self.query[2*seg_ind+1] += q
        
        self.data[2*seg_ind]   += q
        self.data[2*seg_ind+1] += q

        # remove queries from seg_ind
        self.data[seg_ind] = min(self.data[2*seg_ind],self.data[2*seg_ind+1])
        self.query[seg_ind] = 0

    # updates the node seg_ind to know of all queries
    # applied to it via its ancestors
    def update(self,seg_ind):
        # find all indecies to be updated
        seg_ind //= 2
        inds = []
        while seg_ind>0:
            inds.append(seg_ind)
            seg_ind//=2
       
        # push the queries down the segment tree
        for ind in reversed(inds):
            self.push(ind)

    # make the changes to seg_ind be known to its ancestors
    def build(self,seg_ind):
        seg_ind//=2
        while seg_ind>0:
            self.data[seg_ind] = min(self.data[2*seg_ind], self.data[2*seg_ind+1]) + self.query[seg_ind]
            seg_ind //= 2

    # lazily add value to [l,r)
    def add(self,l,r,value):
        l += self.m
        r += self.m
        
        l0 = l
        r0 = r

        while l<r:
            if l%2==1:
                self.query[l]+= value
                self.data[l] += value
                l+=1
            if r%2==1:
                r-=1
                self.query[r]+= value
                self.data[r] += value
            l//=2
            r//=2

        # tell all nodes above of the updated
        # area of the updates
        self.build(l0)
        self.build(r0-1)
    
    # min of data[l,r)
    def min(self,l,r):
        l += self.m
        r += self.m

        # apply all the lazily stored queries
        self.update(l)
        self.update(r-1)
        
        segs = []
        while l<r:
            if l%2==1:
                segs.append(l)
                l+=1
            if r%2==1:
                r-=1
                segs.append(r)
            l//=2
            r//=2

        return min(self.data[ind] for ind in segs)


    # find index of smallest value in data[l,r)
    def find_min(self,l,r):
        l += self.m
        r += self.m
        
        # apply all the lazily stored queries
        self.update(l)
        self.update(r-1)

        segs = []
        while l<r:
            if l%2==1:
                segs.append(l)
                l+=1
            if r%2==1:
                r-=1
                segs.append(r)
            l//=2
            r//=2

        ind = min(segs, key=lambda i:self.data[i])
        mini = self.data[ind]
       
        # dig down in search of mini
        while ind<self.m:
            self.push(ind)

            if self.data[2*ind]==mini:
                ind *= 2
            else:
                ind = 2*ind+1
        
        return ind-self.m,mini


n,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

inter = []
update = [[] for _ in range(n+1)]
for _ in range(m):
    l,r = [int(x) for x in input().split()]
    l -= 1
    inter.append((l,r))
    update[l].append((l,r))
    update[r].append((l,r))

Aneg = super_seg([-a for a in A])
besta = -1
besta_ind = -1

active_intervals = 0
for i in range(n):
    for l,r in update[i]:
        Aneg.add(l,r,1 if l==i else -1)
        active_intervals += 1 if l==i else -1 
    Amax = -Aneg.data[1]
    Ai = A[i] - active_intervals
    if Amax-Ai>besta:
        besta = Amax-Ai
        besta_ind = i

ints = [i for i in range(m) if inter[i][0]<=besta_ind<inter[i][1]]
print(besta)
print(len(ints))
print(' '.join(str(x+1) for x in ints))