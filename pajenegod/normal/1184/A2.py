import sys
range = xrange
input = raw_input

n = int(input())
y = [int(x) for x in input()]

def poss(k):
    x = [0]*n
    for i in range(n-k):
        x[i + k] = x[i] ^ y[i]
    for i in range(n-k,n):
        if x[i] ^ x[i + k - n] != y[i]:
            return 0
    return 1

possible = [0]*(n+1)

i = 1
while i * i < n:
    if n % i == 0:
        possible[i] = poss(i)
        possible[n//i] = poss(n//i)
    i += 1
if i * i == n:
    possible[i] = poss(i)


def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

ans = 0
for k in range(1, n+1):
    ans += possible[gcd(n,k)]
print ans