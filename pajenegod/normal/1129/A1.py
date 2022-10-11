import sys
range = xrange
input = raw_input

small = -(10**18)
big = 10**18

class seg:
    def __init__(self,n):
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [small]*(2*m)
    def set(self,i,val):
        val += i
        i += self.m 
        while i>0:
            self.data[i] = val
            val = max(val,self.data[i^1])
            i//=2
    def add(self,i,val):
        i += self.m 
        val += self.data[i]
        while i>0:
            self.data[i] = val
            val = max(val,self.data[i^1])
            i//=2

n,m = [int(x) for x in input().split()]
inp = [int(x)-1 for x in sys.stdin.read().split()]
A = inp[::2]
B = inp[1::2]

count = [0]*n
longest = [big]*n

mod_sub = lambda i: i if i>=0 else i+n 
mod_add = lambda i: i if i<n else i-n 

for i in range(m):
    count[A[i]]+=1
    longest[A[i]] = min(longest[A[i]], mod_sub(B[i]-A[i]))

worst = seg(n)
i = 0
for j in range(n):
    if count[j]==0:continue
    worst.set(j,(count[j]-1)*n + longest[j])

out = []
for i in range(n):
    out.append(max(0,worst.data[1]-i))
    if count[i]!=0:
        worst.add(i,n)
print ' '.join(str(x) for x in out)