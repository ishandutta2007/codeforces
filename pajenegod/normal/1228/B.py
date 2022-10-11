import sys
range = xrange
input = raw_input

def printer(x):
    print x
    sys.exit()
MOD = 10**9 + 7

n,m = [int(x) for x in input().split()]

R = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

board = [[0]*m for _ in range(n)]

for j in range(m):
    c = C[j]
    for i in range(c):
        board[i][j] = 1
    if c < n:
        board[c][j] = 2

for i in range(n):
    r = R[i]
    boardi = board[i]
    for j in range(r):
        if boardi[j] == 2:
            printer(0)
        boardi[j] = 1
    if r < m:
        if boardi[r] == 1:
            printer(0)
        boardi[r] = 2
print pow(2, sum(b==0 for row in board for b in row), MOD)