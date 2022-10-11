import sys
range = xrange
input = raw_input

n = int(input())

counter = [[0]*3 for _ in range(3)]
for i,c in enumerate(input()):
    if c=='R':
        counter[i%3][0] += 1
    elif c=='G':
        counter[i%3][1] += 1
    else:
        counter[i%3][2] += 1

best = 10000000000
best_ind = -1
for ind in [(0,1,2),(0,2,1),(1,0,2),(1,2,0),(2,0,1),(2,1,0)]:
    cost = sum(counter[0])-counter[0][ind[0]]
    cost += sum(counter[1])-counter[1][ind[1]]
    cost += sum(counter[2])-counter[2][ind[2]]
    if cost<best:
        best = cost
        best_ind = ind

arr = 'RGB'

out = [arr[best_ind[i%3]] for i in range(n)]
print best
print ''.join(out)