import sys
range = xrange
input = sys.stdin.readline

class seg:
    def __init__(self,data):
        n = len(data)
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m

        self.data = [0]*(m+m)
        for i in range(n):
            self.data[i+m] = data[i]
        for i in reversed(range(m)):
            self.data[i] = self.data[2*i] + self.data[2*i+1]
    def sum(self,l,r):
        l += self.m
        r += self.m

        s = 0
        while l<r:
            if l%2==1:
                s += self.data[l]
                l += 1
            if r%2==1:
                r -= 1
                s += self.data[r]
            l//=2
            r//=2
        return s

    # First index i when sum(data[:i+1])>T
    def search(self,T):
        i = 1
        while i<self.m:
            if self.data[2*i]>T:
                i = 2*i
            else:
                T-=self.data[2*i]
                i = 2*i+1
        return i - self.m

    def set(self,i,val):
        i += self.m
        diff = self.data[i]-val

        while i>0:
            self.data[i]-=diff
            i//=2


n,T = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

Aseg = seg(A)

left = n

bought = 0
while left:
    lap = Aseg.data[1]
    bought += left*(T//lap)
    T %= lap

    while T<Aseg.data[1]:
        a = Aseg.search(T)
        # can pay for A[0:a] but not for A[0:a+1]
        # remove A[a]
        A[a] = 0
        Aseg.set(a,0)
        left -= 1

print bought