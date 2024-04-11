import sys
range = xrange
input = raw_input

def mini(x,y):
    if x == -1:
        return y
    if y == -1:
        return x
    return min(x, y)

t = int(input())
for _ in range(t):
    n,c = [int(x) for x in input().split()]

    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()] + [0]

    mon = 0
    cost = 0
    best_cost = -1

    for i in range(n):
        a = A[i]
        b = B[i]
        
        if mon >= c:
            wait = 0
        else:
            wait = (c - mon + a - 1) // a

        best_cost = mini(best_cost, cost + wait)

        if mon >= b:
            wait = 0
        else:
            wait = (b - mon + a - 1) // a

        mon += wait * a - b
        cost += wait + 1
    print best_cost