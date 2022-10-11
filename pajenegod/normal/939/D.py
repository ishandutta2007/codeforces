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


n = int(input())

s1 = input()
s2 = input()

A = mergefind(26)

spells = set()
dum = ord('a')

for i in range(n):
    a = s1[i]
    b = s2[i]
    a = ord(a)-dum
    b = ord(b)-dum
    A.merge(a,b)

spells = set()
for c in range(26):
    d = A.find(c)
    if d!=c:
        spells.add((c,d))

print len(spells)
for a,b in spells:
    a = chr(a+dum)
    b = chr(b+dum)
    print a,b