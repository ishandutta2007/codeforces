from itertools import permutations as perm
import sys
range = xrange
input = raw_input

n = int(input())
C = [c for line in sys.stdin for c in line if c=='0' or c=='1']

B = []
for i in range(4):
    B.append(C[n*n*i:(i+1)*n*n])

opp = {'0':'1','1':'0'}

besta = 100000000000000
for P in perm([0,1,2,3]):
    for I in '01':
        cost = 0
        for i in range(n*n):
            if i%2==0:
                goal = I
            else:
                goal = opp[I]
            if B[P[0]][i]!=goal:
                cost+=1
        for i in range(n*n):
            if i%2==0:
                goal = I
            else:
                goal = opp[I]
            if B[P[1]][i]!=goal:
                cost+=1
        for i in range(n*n):
            if i%2==1:
                goal = I
            else:
                goal = opp[I]
            if B[P[2]][i]!=goal:
                cost+=1
        for i in range(n*n):
            if i%2==1:
                goal = I
            else:
                goal = opp[I]
            if B[P[3]][i]!=goal:
                cost+=1
        besta = min(besta,cost)
print(besta)