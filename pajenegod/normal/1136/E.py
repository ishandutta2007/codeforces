from __future__ import division, print_function
import os,sys,atexit

if sys.version_info[0] < 3:
    range = xrange
    from cStringIO import StringIO
    sys.stdout = StringIO()
else:
    from io import BytesIO as StringIO
    sys.stdout = StringIO()
    _write = sys.stdout.write
    sys.stdout.write = lambda s: _write(s.encode())
atexit.register(lambda: os.write(1, sys.stdout.getvalue()))

input = StringIO(os.read(0, os.fstat(0).st_size)).readline

import _numpypy
np = _numpypy.multiarray

# windows pypy is 32 bit
# So I'm using longlong from numpypy
lltype = np.dtype('int64')
llzero = lltype.type(0)
def ll(x):return llzero + x


# A very nice implementation of a minimum segment tree with 
# some inspiration taken from https://codeforces.com/blog/entry/18051
# This implementation should be able to be modified to do pretty
# much anything one would want to do with segment trees apart from
# persistance.
# Note that especially in python this implementation is much much better
# than most other approches because how slow python can be with function
# calls.

# Currently it allows for two operations, both running in O(log n),
# 'set(l,r,value)' sets value to [l,r)
# 'find_min(l,r)' finds the index with the smallest value

MAX = ll(2**63)

class super_seg:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n: m *= 2
        
        self.n = n
        self.m = m
        self.data = np.zeros(2*m,lltype)
        for i in range(n):
            self.data[i+m] = data[i]
        for i in reversed(range(m)):
            self.data[i] = self.data[2*i] + self.data[2*i+1]
        self.query = [MAX]*(2*m)
    
    # Push the query on seg_ind to its children
    def push(self,seg_ind,si):
        # Let the children know of the queries
        setter = self.query[seg_ind]

        if setter!=MAX:
            self.query[2*seg_ind]   = setter
            self.query[2*seg_ind+1] = setter
            
            self.data[2*seg_ind]   = (si//2) * setter
            self.data[2*seg_ind+1] = (si//2) * setter

            # Remove queries from seg_ind
            self.data[seg_ind] = self.data[2*seg_ind] + self.data[2*seg_ind+1]
            self.query[seg_ind] = MAX

    # Updates the node seg_ind to know of all queries
    # applied to it via its ancestors
    def update(self,seg_ind):
        # Find all indecies to be updated
        seg_ind //= 2
        inds = []
        while seg_ind>0:
            inds.append(seg_ind)
            seg_ind//=2
       
        # Push the queries down the segment tree
        si = self.m
        for ind in reversed(inds):
            self.push(ind,si)
            si//=2

    # Make the changes to seg_ind be known to its ancestors
    def build(self,seg_ind):
        seg_ind//=2
        #si = 2
        while seg_ind>0:
            if self.query[seg_ind]==MAX:
                self.data[seg_ind] = self.data[2*seg_ind] + self.data[2*seg_ind+1]
            #else:    
            #    self.data[seg_ind] = si*self.query[seg_ind]
            seg_ind //= 2
            #si*=2

    # Lazily add value to [l,r)
    def setter(self,l,r,value):
        l += self.m
        r += self.m
        
        l0 = l
        r0 = r
        si = 1

        while l<r:
            if l%2==1:
                self.query[l] = value
                self.data[l] = value*si
                l+=1
            if r%2==1:
                r-=1
                self.query[r] = value
                self.data[r]  = value*si
            l//=2
            r//=2
            si *= 2

        # Tell all nodes above of the updated
        # area of the updates
        self.build(l0)
        self.build(r0-1)
    
    # Min of data[l,r)
    def summa(self,l,r):
        l += self.m
        r += self.m

        # Apply all the lazily stored queries
        self.update(l)
        self.update(r-1)
        
        segs = llzero
        while l<r:
            if l%2==1:
                segs += self.data[l]
                l+=1
            if r%2==1:
                r-=1
                segs += self.data[r] 
            l//=2
            r//=2

        return segs



n = int(input())
A = [ll(int(x)) for x in input().split()]
K = [ll(int(x)) for x in input().split()]

Kcumsum = np.zeros(len(K)+1,lltype)
for i,k in enumerate(K):
    Kcumsum[i+1] = Kcumsum[i]+k

# new A[i] is guaranteed to be increasing as a_i+k_i<=a_i+1 is now a_i<=a_i+1
extra = np.zeros(n,lltype)
for i in range(n):
    A[i] += Kcumsum[n-1] - Kcumsum[i]
    extra[i] = Kcumsum[n-1] - Kcumsum[i]

extra_cumsum = np.zeros(len(extra)+1,lltype)
for i,e in enumerate(extra):
    extra_cumsum[i+1] = extra_cumsum[i] + e

sumseg = super_seg(A)

q = int(input())
for _ in range(q):
    a,b,c = input().split()
    if a=='+':
        i,x = int(b)-1,ll(int(c))
        new_val = x + sumseg.summa(i,i+1)

        a = i
        b = n
        while a<b:
            c = (a+b+1)//2
            if sumseg.summa(c,c+1)<new_val:
                a = c
            else:
                b = c-1
        sumseg.setter(i,a+1,new_val)

    else:
        l,r = int(b)-1,int(c)

        ans = sumseg.summa(l,r)

        # TRANSFORM BACK
        ans -= extra_cumsum[r]-extra_cumsum[l]
        sys.stdout.write(str(ans))
        sys.stdout.write('\n')