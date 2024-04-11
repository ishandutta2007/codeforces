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
sign = 1
 
for i in range(len(s)):
    if s[i]>='0':
        numb = 10*numb + ord(s[i])-48
    else:
        if s[i]=='-':
            sign = -1
        else:
            inp.append(sign*numb)
            numb = 0
            sign = 1
if s[-1]>='0':
    inp.append(sign*numb)
ii = 0


n = inp[ii]
ii += 1
m = inp[ii]
ii += 1
k = inp[ii]
ii += 1

X = [x-1 for x in inp[ii:ii+k]]
ii += k

edges = []
for _ in range(m):
    u = inp[ii]-1
    ii += 1
    v = inp[ii]-1
    ii += 1
    w = inp[ii]
    ii += 1

    edges.append((w,u,v))
j = 0
edges.sort()
MF = mergefind(n)
for w,u,v in edges:
    MF.merge(u,v)
    while j<len(X) and MF.find(X[0])==MF.find(X[j]):j+=1
    if j==len(X):
        break

print ' '.join(str(w) for _ in range(k))