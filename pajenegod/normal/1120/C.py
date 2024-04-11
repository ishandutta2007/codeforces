import sys
range = xrange
input = raw_input

n,A,B = [int(x) for x in input().split()]
s = input()

DP = [0]*(n+1)
for i in range(n):
    a = 0
    b = i+1
    while a!=b:
        c = (a+b)//2
        if s[c:i+1] in s[:c]:
            b = c
        else:
            a = c+1

    if a==i+1:
        score = 10**9
    else:
        score = DP[a]+B

    score = min(score,DP[i]+A)
    DP[i+1] = score
print DP[n]