import sys
input = raw_input

t = int(input())
for _ in range(t):
    l,r = [int(x) for x in input().split()]
    print r % max(r // 2 + 1, l)