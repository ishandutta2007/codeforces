import sys
t = int(input())
for _ in range(t):
    n = input()
    if len(n) > 2:
        print(min(n))
    else:
        print(n[1])