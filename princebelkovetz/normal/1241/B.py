from sys import stdin, stdout, setrecursionlimit
# plz solve div2c
input = stdin.readline

for _ in range(int(input())):
    s = set(input()[:-1])
    t = set(input()[:-1])
    # print(s, t)
    print('Yes') if len(s.intersection(t)) > 0 else print('No')