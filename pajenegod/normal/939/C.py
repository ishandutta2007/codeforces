
import sys
range = xrange
input = raw_input


class seg:
    def __init__(self, n):
        self.n = n
        m = 1
        while m<n:
            m*=2
        self.m = m
        self.data = [0]*(2*m)
    def add(self,l,r,val):
        l += self.m
        r += self.m
        while l<r:
            if l%2==1:
                self.data[l] += val
                l+=1
            if r%2==1:
                r-=1
                self.data[r] += val
            l//=2
            r//=2
    def sums(self):
        for i in range(self.m):
            val = self.data[i]
            self.data[2*i] += val
            self.data[2*i+1] += val
        return self.data[self.m:self.m+self.n]

n = int(input())
A = [int(x) for x in input().split()]
s,f = [int(x) for x in input().split()]

duper = seg(300000)

for i in range(n):
    l = -i+s+n
    r = -i+f+n

    duper.add(l,r,A[i])
    l = n-i+s+n
    r = n-i+f+n

    duper.add(l,r,A[i])
    #l = (i+s-1)%n+1
    #r = (i+f-1)%n+1

    #if r<=l:
    #    duper.add(l,n+1,A[i])
    #    duper.add(1,r,A[i])
    #else:
    #    duper.add(l,r,A[i])
best = duper.sums()
#print best[99900:100100]
#print best[1:100]

best_ind = -1
bests = -10000000000
for i in range(300000):
    if best[i]>bests or (best[i]==bests and (best_ind-1)%n>(i-1)%n ):
        bests = best[i]
        best_ind = i


print (best_ind+n-1)%n+1