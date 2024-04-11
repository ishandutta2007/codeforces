import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x)-1 for x in input().split()]
A.sort()


# even
goal = 0
moves = 0
for a in A:
    moves += abs(goal-a)
    goal += 2
best =  moves

# odd
goal = 1
moves = 0
for a in A:
    moves += abs(goal-a)
    goal += 2
best = min(moves,best)

print(best)