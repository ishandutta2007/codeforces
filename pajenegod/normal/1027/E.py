import sys
range = xrange
input = raw_input

MOD = 998244353

class sumseg:
    def __init__(self,n):
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [0]*(n+m)
    def summa(self,l,r):
        l+=self.m
        r+=self.m
        s = 0
        while l<r:
            if l%2==1:
                s+=self.data[l]
                l+=1
            if r%2==1:
                r-=1
                s+=self.data[r]
            l//=2
            r//=2
        return s%MOD
    def add(self,ind,val):
        ind += self.m
        while ind>0:
            self.data[ind] = (self.data[ind]+val)%MOD
            ind//=2


n,k = [int(x) for x in input().split()]

switchers = [0]*(n+1)

for h in range(1,n+1):
    DP = sumseg(n+1)#[0]*(n+1)
    DP.add(0,2)#DP[0] = 2
    max_width = (k+h-1)//h - 1
    for i in range(1,n+1):
        a = max(i-max_width,0)
        b = i
        if a<b:
            DP.add(i,DP.summa(a,b))#DP[i] = sum(DP[a:b])%MOD
    
    switchers[h]=DP.summa(n,n+1)

for h in range(1,n):
    switchers[h] = (switchers[h]-switchers[h+1])%MOD


switchers2 = [0]*(n+1)

for h in range(1,n+1):
    DP = sumseg(n+1)#[0]*(n+1)
    DP.add(0,1)#DP[0] = 2
    max_width = h
    for i in range(1,n+1):
        a = max(i-max_width,0)
        b = i
        if a<b:
            DP.add(i,DP.summa(a,b))#DP[i] = sum(DP[a:b])%MOD
    
    switchers2[h]=DP.summa(n,n+1)



summa = 0
for h in range(1,n+1):
    summa = (summa + switchers[h]*switchers2[h])%MOD
print summa