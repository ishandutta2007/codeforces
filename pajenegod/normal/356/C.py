import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

count = [0]*5
for a in A:
    count[a] += 1

count[0] = 0

Asum = sum(i*count[i] for i in range(5))

inf = 10**9
besta = inf

goal = [0,0,0,0,Asum//4]
if Asum % 4 != 0:
    goal[Asum%4] += 1

for i in range(3):
    if goal[i]:
        goal[i] -= 1
        goal[i + 1] += 1
        goal[4] -= 1
        goal[3] += 1

while goal[4] >= 0 and sum(goal) <= n:
    moves = 0
    diff = [count[i] - goal[i] for i in range(5)]
    # either 2 or 4
    x = min(diff[2], diff[4])
    if x > 0:
        diff[2] -= x
        diff[4] -= x
        diff[3] += 2*x
        moves += x
    
    x = min(diff[1]//2, diff[4])
    if x > 0:
        diff[1] -= 2 * x
        diff[4] -= x
        diff[3] += 2 * x
        moves += 2 * x
    
    x = min(diff[1], diff[4]//2)
    if x > 0:
        diff[1] -= x
        diff[4] -= 2 * x
        diff[3] += 3 * x
        moves += 2 * x

    # either 1 or 3
    x = min(diff[1], diff[3])
    if x > 0:
        diff[1] -= x
        diff[3] -= x
        diff[4] += x
        moves += x

    x = min(diff[1], diff[2], -diff[3])
    if x > 0:
        diff[1] -= x
        diff[2] -= x
        diff[3] += x
        moves += x

    x = min(diff[1]//2, diff[2], -diff[4])
    if x > 0:
        diff[1] -= 2*x
        diff[2] -= x
        diff[4] += x
        moves += 2*x
    
    x = min(diff[1]//4, -diff[4])
    if x > 0:
        diff[1] -= 4 * x
        diff[4] += x
        moves += 3*x

    x = min(diff[1]//3, -diff[3])
    if x > 0:
        diff[1] -= 3 * x
        diff[3] += x
        moves += 2*x

    x = min(diff[2]//2, -diff[4])
    if x > 0:
        diff[2] -= 2*x
        diff[4] += x
        moves += 2*x

    x = min(diff[1]//3, -diff[3])
    if x > 0:
        diff[2] -= 3 * x
        diff[3] += 2 * x
        moves += 2 * x
    
    x = min(diff[2], diff[3]//2)
    if x > 0:
        diff[2] -= x
        diff[3] -= 2 * x
        diff[4] += 2 * x
        moves += 2 * x

    x = min(diff[2]//3, (-diff[3])//2)
    if x > 0:
        diff[2] -= 3 * x
        diff[3] += 2 * x
        moves += 2 * x
    
    x = min((-diff[3])//4, diff[4]//3)
    if x > 0:
        diff[4] -= 3 * x
        diff[3] += 4 * x
        moves += 3 * x
    
    x = min(diff[3]//4, (-diff[4])//3)
    if x > 0:
        diff[4] += 3 * x
        diff[3] -= 4 * x
        moves += 3 * x
    assert(not any(diff))

    besta = min(besta, moves)
    # 12
    # 14
    # 23
    # 34



    goal[4] -= 3
    goal[3] += 4

if besta == inf:
    print -1
else:
    print besta