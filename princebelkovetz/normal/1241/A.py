from sys import stdin, stdout, setrecursionlimit
# plz solve div2c
input = stdin.readline

for _ in range(int(input())):
    n = int(input())
    if n < 4:
        print(4 - n)
    else:
        print(n % 2)