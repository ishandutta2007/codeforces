# Test without fastIO
# With fastIO it takes 326 ms

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


def main():
    n = int(input())

    dsu = mergefind(n)

    inp = [int(x) for _ in range(n-1) for x in input().split()]
    
    ii = 0
    for _ in range(n-1):
        u,v,c = inp[ii]-1,inp[ii+1]-1,inp[ii+2]
        ii += 3
        
        if c==1:
            dsu.merge(u,v)
    
    dsu2 = mergefind(n)
    for i in range(n):
        dsu2.size[i] = dsu.size[dsu.find(i)]

    ii = 0
    for _ in range(n-1):
        u,v,c = inp[ii]-1,inp[ii+1]-1,inp[ii+2]
        ii += 3
        
        if c==0:
            dsu2.merge(u,v)

    pairs = 0
    for i in range(n):
        i = dsu2.find(i)
        pairs += dsu2.size[i]-1
    print pairs




######## Python 2 and 3 footer by Pajenegod and c1729 

py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange
    from cStringIO import StringIO as BytesIO
    input = raw_input
else:
    from io import BytesIO
    __str__ = str
    str = lambda x=b'': x if type(x) is bytes else __str__(x).encode()

if __name__== "__main__":
  main()