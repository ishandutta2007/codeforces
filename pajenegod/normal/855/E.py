import sys
range = xrange
input = raw_input

def int2base(n, base):
    if n == 0:
        return [0]
    A = []
    while n:
        n,r = divmod(n, base)
        A.append(r)
    return A

big = 10**18
DP =   [[[0]*(1 << b) for _ in range(b>1 and len(int2base(big, b)) + 1)] for b in range(11)]
DP0 =  [[[0]*(1 << b) for _ in range(b>1 and len(int2base(big, b)) + 1)] for b in range(11)]

for b in range(2,11):
    DPb = DP[b]
    DP0b = DP0[b]

    DP0b[0][0] = 1
    
    for l in range(1, len(DPb)):
        for mask in range(1 << b):
            for digit in range(b):
                DP0b[l][mask ^ (1 << digit)] += DP0b[l - 1][mask]
            
            for digit in range(1, b):
                DPb[l][mask ^ (1 << digit)] += DP0b[l - 1][mask]
                
inp = sys.stdin.read().split()
ii = 0

# < upper
def counter(upper, base):
    if upper <= base:
        return 0
    number = int2base(upper, base)
    DPb = DP[base]
    DP0b = DP0[base]

    mask = 0
    n = number.pop()
    ans = 0
    for l in range(len(number) + 1):
        ans += DPb[l][0]
    
    for digit in range(1, n):
        ans += DP0b[len(number)][mask ^ (1 << digit)]
    mask ^= 1 << n
    
    while number:
        n = number.pop()
        for digit in range(n):
            ans += DP0b[len(number)][mask ^ (1 << digit)]
        mask ^= 1 << n
    return ans
            
q = int(inp[ii]); ii += 1

out = []
for _ in range(q):
    b = int(inp[ii]); ii += 1
    l = int(inp[ii]); ii += 1
    r = int(inp[ii]); ii += 1

    out.append(str(counter(r + 1, b) - counter(l, b)))

print '\n'.join(out)