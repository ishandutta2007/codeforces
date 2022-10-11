import sys
range = xrange
input = raw_input

class seg:
    def __init__(self,n):
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [(-1,-1)]*(n+m)
    def setter(self,l,r,val):
        l += self.m
        r += self.m
        while l<r:
            if l%2==1:
                self.data[l]=max(self.data[l],val)
                l+=1
            if r%2==1:
                r-=1
                self.data[r]=max(self.data[r],val)
            l//=2
            r//=2
    def maxxer(self,ind):
        ind += self.m
        val = (-1,-1)
        while ind>0:
            val = max(val,self.data[ind])
            ind//=2
        return val


n = int(input())
inp = [int(x) for line in sys.stdin for x in line.split()]

mapper = {}
unused = 0
A = sorted(inp)
for a in A:
    if a not in mapper:
        mapper[a]=unused
        unused+=1

inp = [mapper[i] for i in inp]

segtree = seg(unused) 
for i in sorted(list(range(n)),key=lambda i:inp[2*i+1]-inp[2*i],reverse=True):
    L = inp[2*i]
    R = inp[2*i+1]+1
    cover,j = segtree.maxxer(L)
    if cover>=R:
        print i+1,j+1
        sys.exit()
    segtree.setter(L,R,(R,i))
print -1,-1