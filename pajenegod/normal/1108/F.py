import sys
range = xrange
input = raw_input


class mergefind:
    def __init__(self,n):
        self.parent = list(range(n))
        self.size = [1]*n
        self.num_sets = n

    def find(self,a):
        to_update = []
       
        while a != self.parent[a]:
            to_update.append(a)
            a = self.parent[a]
       
        for b in to_update:
            self.parent[b] = a

        return self.parent[a]

    def merge(self,a,b):
        a = self.find(a)
        b = self.find(b)

        if a==b:
            return

        if self.size[a]<self.size[b]:
            a,b = b,a

        self.num_sets -= 1
        self.parent[b] = a
        self.size[a] += self.size[b]

    def set_size(self, a):
        return self.size[self.find(a)]

    def __len__(self):
        return self.num_sets

s = sys.stdin.read()
inp = []
numb = 0
 
for i in range(len(s)):
    if s[i]>='0':
        numb = 10*numb + ord(s[i])-48
    else:
        inp.append(numb)
        numb = 0
if s[-1]>='0':
    inp.append(numb)

ii = 0

n = inp[ii]
ii += 1
m = inp[ii]
ii += 1

edge_order = sorted(range(m),key = lambda i: inp[ii+3*i+2])

mf = mergefind(n)

j = 0
count = 0
while len(mf)!=1:
    val = inp[ii+3*edge_order[j]+2]

    useable = []
    while j<m and inp[ii+3*edge_order[j]+2]==val:
        u = inp[ii+3*edge_order[j]]-1
        v = inp[ii+3*edge_order[j]+1]-1
        
        if mf.find(u)!=mf.find(v):
            useable.append(edge_order[j])
        j+=1

    for i in useable:
        u = inp[ii+3*i]-1
        v = inp[ii+3*i+1]-1
        
        if mf.find(u)==mf.find(v):
            count += 1
        else:
            mf.merge(u,v)
print count