import sys
range = xrange
input = raw_input

n = int(input())
S = input()

X,Y = [int(x) for x in input().split()]

if (X+Y+n)%2==1:
    print -1
    sys.exit()

counter = [[0]*(n+1) for _ in range(4)]
for i in range(n):
    c = S[i]
    counter[0][i+1] = counter[0][i]
    counter[1][i+1] = counter[1][i]
    counter[2][i+1] = counter[2][i]
    counter[3][i+1] = counter[3][i]
    if c=='R':
        counter[0][i+1] += 1
    elif c=='L':
        counter[1][i+1] += 1
    elif c=='U':
        counter[2][i+1] += 1
    else:
        counter[3][i+1] += 1

best = n+1
for i in range(n):
    a = i
    b = n+1
    while a!=b:
        mid = (a+b)//2
        
        Rs = counter[0][-1] - (counter[0][mid] - counter[0][i])
        Ls = counter[1][-1] - (counter[1][mid] - counter[1][i])
        Us = counter[2][-1] - (counter[2][mid] - counter[2][i])
        Ds = counter[3][-1] - (counter[3][mid] - counter[3][i])

        interval = mid-i
        mx = Rs-Ls
        my = Us-Ds

        if abs(X-mx)+abs(Y-my)<=interval:
            b = mid
        else:
            a = mid+1
    if b!=n+1:
        best = min(b-i,best)
if best==n+1:
    print -1
else:
    print best