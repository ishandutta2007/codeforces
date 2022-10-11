import sys
range = xrange
input = raw_input

n = int(input())

class mergefind:
    def __init__(self,n):
        self.parent = list(range(n))
        self.size = [1]*n
        self.num_sets = n
        self.lista = [[_] for _ in range(n)]

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
        self.lista[a] += self.lista[b]

    def set_size(self, a):
        return self.size[self.find(a)]

    def __len__(self):
        return self.num_sets


inp = [int(x)-1 for x in sys.stdin.read().split()]
X = inp[::2]
Y = inp[1::2]

mf = mergefind(n)

for i in range(n-1):
    mf.merge(X[i],Y[i])

print ' '.join(str(x+1) for x in mf.lista[mf.find(0)])