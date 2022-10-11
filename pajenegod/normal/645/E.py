import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

s = list(ord(c)-97 for c in input())
n += len(s)

last = [-1]*k
for i in range(len(s)):
    last[s[i]] = i

while len(s)<n:
    letter = min(range(k),key = lambda i:last[i])
    last[letter] = len(s)
    s.append(letter)

DP = [0]*n
cumsum = [0]*(n+1)
cumsum[0] = 1
last_sum = [0]*k

# cumsum[i] is [-1,i)
a = 1
b = 0
MOD = 10**9+7

for i in range(n):
    b = (2*a%MOD - last_sum[s[i]])%MOD
    last_sum[s[i]] = a
    a = b

print a