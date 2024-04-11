n = int(input())
# Using the same index I would for a tree
m = 2**n

points = [0]*(2*m)
points[1] = 2**(n-1)
for i in range(1,m):
    x = points[i]//2
    points[2*i] = x
    points[2*i+1] = x



P = [[int(x)/100.0 for x in input().split()] for _ in range(m)]
state = [[0.0]*64 for _ in range(2*m)]

for i in range(m):
    state[m+i][i] = 1.0
    
for i in reversed(range(1,m)):
    for j in range(m):
        for k in range(j+1,m):
            # x is probability that team j meets team k in match i
            x = state[2*i][j]*state[2*i+1][k]

            state[i][j] += P[j][k]*x
            state[i][k] += P[k][j]*x

score = [[0]*64 for _ in range(2*m)]
for i in reversed(range(1,m)):
    for j in range(m):
        for k in range(m):
            score[i][j] = max(score[i][j], score[2*i][j]+state[i][j]*points[i] + score[2*i+1][k])
            score[i][j] = max(score[i][j], score[2*i+1][j]+state[i][j]*points[i] + score[2*i][k])
print(repr(max(score[1])))