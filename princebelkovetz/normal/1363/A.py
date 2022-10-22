from sys import stdin, stdout, setrecursionlimit
# plz solve div2c
input = stdin.readline

for _ in range(int(input())):
    n, x = map(int, input().split())
    a = [int(i) % 2 for i in input().split()]
    cou2 = 0
    cou1 = 0
    for b in a:
        if b == 0:
            cou1 += 1
        else:
            cou2 += 1
    for i in range(1, min(x + 1, cou2 + 1), 2):
        if x - i <= cou1:
            print('Yes')
            break
    else:
        print('No')