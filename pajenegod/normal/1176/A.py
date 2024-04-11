import sys
range = xrange
input = raw_input



q = int(input())
for _ in range(q):
    n = int(input())
    moves = 0
    while n%5==0:
        moves += 1
        n = 4*(n//5)

    while n%3==0:
        moves  += 1
        n = 2*(n//3)

    while n%2==0:
        moves += 1
        n //= 2

    if n == 1:
        print moves
    else:
        print -1