from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    x = input()
    a = []
    for i in range (len(x) - 1, -1 , -1):
        if x[i] != '0':
            a.append(x[i] + '0' * (len(x) - 1 - i))
    print(len(a))
    print(*a)