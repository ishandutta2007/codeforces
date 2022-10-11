import sys
range = xrange
input = raw_input
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
t = inp[ii]; ii += 1
 
for _ in range(t):
    n = inp[ii]; ii += 1
 
    T = inp[ii + 0: ii + 2 * n: 2]
    X = inp[ii + 1: ii + 2 * n: 2]
    ii += 2 * n
 
    T.append(2 * 10**18)
 
    count = 0
 
    cur_x = 0
    goal_x = 0
    for i in range(n):
        x = X[i]
        t = T[i]
        tp1 = T[i + 1]
 
        if cur_x == goal_x:
            goal_x = x
            
        if abs(x - cur_x) <= tp1 - t and (goal_x <= x <= cur_x or goal_x >= x >= cur_x):
            count += 1
 
        if cur_x < goal_x:
            cur_x = min(goal_x, cur_x + tp1 - t)
        elif cur_x > goal_x:
            cur_x = max(goal_x, cur_x - (tp1 - t))
    print count