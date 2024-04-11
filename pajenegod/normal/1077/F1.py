import sys
range = xrange
input = raw_input

inf = 10**16

class maxseg:
    def __init__(self,n):
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [-inf]*(m+m)

    def set(self,ind,val):
        ind += self.m
        self.data[ind]=val
        ind //= 2
        while ind>0 and self.data[ind]<val:
            self.data[ind] = val
            ind//=2
    def get(self,l,r):
        l += self.m
        r += self.m
        val = -inf
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

n,k,X = [int(x) for x in input().split()]

s = sys.stdin.read()
A = []
numb = 0
 
for i in range(len(s)):
    if s[i]>='0':
        numb = 10*numb + ord(s[i])-48
    else:
        A.append(numb)
        numb = 0
if s[-1]>='0':
    A.append(numb)

DP = [maxseg(n+1) for _ in range(X+1)]
DP[X].set(0,0)

for x in reversed(range(0,X)):
    for i in range(1,n+1):
        DP[x].set(i,DP[x+1].get(max(i-k,0),i) + A[i-1])


ans = DP[0].get(max(n-k+1,0),n+1)

if ans<0:
    print(-1)
else:
    print(ans)