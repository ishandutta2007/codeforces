import sys
range = xrange

class minseg:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [10**10]*(m+m)
        for i in range(n):
            self.data[i+m] = data[i]
        for i in reversed(range(m)):
            self.data[i] = min(self.data[2*i],self.data[2*i+1])
    def mini(self,l,r):
        l += self.m
        r += self.m
        val = 10**10
        while l<r:
            if l%2==1:
                val = min(val,self.data[l])
                l+=1
            if r%2==1:
                r-=1
                val = min(val,self.data[r])
            l//=2
            r//=2
        return val
    def excl(self,ind):
        return min(self.mini(0,ind),self.mini(ind+1,self.n))
class maxseg:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [-10**10]*(m+m)
        for i in range(n):
            self.data[i+m] = data[i]
        for i in reversed(range(m)):
            self.data[i] = max(self.data[2*i],self.data[2*i+1])
    def maxi(self,l,r):
        l += self.m
        r += self.m
        val = -10**10
        while l<r:
            if l%2==1:
                val = max(val,self.data[l])
                l+=1
            if r%2==1:
                r-=1
                val = max(val,self.data[r])
            l//=2
            r//=2
        return val
    def excl(self,ind):
        return max(self.maxi(0,ind),self.maxi(ind+1,self.n))

inp = [int(x) for line in sys.stdin for x in line.split()]
ii = 0

n = inp[ii]
ii+=1

maxl = maxseg(inp[ii:ii+4*n:4])
ii+=1
maxd = maxseg(inp[ii:ii+4*n:4])
ii+=1
minr = minseg(inp[ii:ii+4*n:4])
ii+=1
minu = minseg(inp[ii:ii+4*n:4])
ii+=1


for excl in range(n):
    l = maxl.excl(excl)
    r = minr.excl(excl)
    d = maxd.excl(excl)
    u = minu.excl(excl)

    if l<=r and d<=u:
        print (l+r)//2,(u+d)//2
        sys.exit()