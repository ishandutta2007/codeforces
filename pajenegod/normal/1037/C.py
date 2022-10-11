import sys
range = xrange
input = sys.stdin.readline

n = int(input())

A = input()
B = input()
A = A[:n]
B = B[:n]

A = [a=='1' for a in A]
B = [b=='1' for b in B]

DP = [[-1]*n for _ in range(2)]

if A[0]:
    DP[0][0] = 1
    DP[1][0] = 0
else:
    DP[0][0] = 0
    DP[1][0] = 1

for i in range(1,n):
    if A[i] and B[i-1]:
                        #01 -> 10       11 -> 10
        DP[0][i] = min(DP[0][i-1] + 1, DP[1][i-1] + 1)
                        #01 -> 11       11 -> 11
        DP[1][i] = min(DP[0][i-1] + 1, DP[1][i-1])
    
    elif A[i] and not B[i-1]:
                        #01 -> 00       11 -> 00
        DP[0][i] = min(DP[0][i-1] + 1, DP[1][i-1] + 2)
                        #01 -> 01       11 -> 01
        DP[1][i] = min(DP[0][i-1], DP[1][i-1] + 1)
    elif not A[i] and B[i-1]:
                        #00 -> 10       10 -> 10
        DP[0][i] = min(DP[0][i-1] + 1, DP[1][i-1])
                        #00 -> 11       10 -> 11
        DP[1][i] = min(DP[0][i-1] + 2, DP[1][i-1] + 1)
    else: 
                        #00 -> 00       10 -> 00
        DP[0][i] = min(DP[0][i-1], DP[1][i-1]+1)
                        #00 -> 01       10 -> 01
        DP[1][i] = min(DP[0][i-1] + 1, DP[1][i-1] + 1)
if B[n-1]:
    print DP[1][n-1]
else:
    print DP[0][n-1]