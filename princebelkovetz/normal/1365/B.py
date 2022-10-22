from sys import stdin, stdout, setrecursionlimit
# plz solve div2c
for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    if a == sorted(a):
        print("Yes")
    elif 0 in b and 1 in b:
        print("Yes")
    else:
        print("No")