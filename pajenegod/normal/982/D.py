import sys
from collections import defaultdict as di
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

n = int(input())
A = [int(x) for x in input().split()]
big = 10**10
A.append(big)

dum = mergefind(n+1)

val_to_ind = di(list)
for i in range(n):
    val_to_ind[A[i]].append(i)

buckets = [0]*(n+2)
buckets[1] = n+1

best_val = -1
best_k = -1

for a in sorted(set(A)):
    if a==big:
        continue
    for i in val_to_ind[a]:
        prev_size1 = dum.set_size(i)
        prev_size2 = dum.set_size(i+1)
        buckets[prev_size1]-=1
        buckets[prev_size2]-=1

        dum.merge(i,i+1)
        new_size = dum.set_size(i)
        buckets[new_size]+=1
    
    ways = buckets[new_size]
    if len(dum)-ways-buckets[1]==0 and ways>best_val:
        best_val=ways
        best_k=a+1

print best_k