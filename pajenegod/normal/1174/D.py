import sys
range = xrange
input = raw_input

n, x = [int(x) for x in input().split()]

mem = [[] for _ in range(20)]
for k in range(1,20):
    mem[k] = mem[k-1] + [2**(k)-1] + mem[k-1]

m = 2**(x.bit_length()-1)

if x>=2**n:
    ans = mem[n]
else:
    ans = [(2*a+1 if a>=m else a) for a in mem[n-1]]

print len(ans)
print ' '.join(str(a) for a in ans)