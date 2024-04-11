import sys
import os
from __pypy__ import builders
range = xrange

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


s = os.read(0,os.fstat(0).st_size)

inp = []
numb = 0
 
for i in range(len(s)):
    if s[i]>='0':
        numb = 10*numb + ord(s[i])-48
    else:
        if s[i]!='\r':
            inp.append(numb)
            numb = 0
if s[-1]>='0':
    inp.append(numb)

ii = 0

n,m = inp[ii],inp[ii+1]
ii += 2

coupl = [[] for _ in range(n)]
for _ in range(m):
    u,v = inp[ii]-1,inp[ii+1]-1
    ii+=2
    coupl[u].append(v)
    coupl[v].append(u)

MF = mergefind(n)
out = builders.StringBuilder()

root = max(range(n),key=lambda i:len(coupl[i]))
Q = list(range(n)) + [root]
while Q:
    node = Q.pop()
    for nei in coupl[node]:
        if MF.find(node)!=MF.find(nei):
            MF.merge(node,nei)
            out.append(str(node+1))
            out.append(" ")
            out.append(str(nei+1))
            out.append("\n")

os.write(1,out.build())