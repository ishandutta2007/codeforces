#from sys import stdin, stdout, setrecursionlimit
#input = stdin.readline
#print = stdout.write

for _ in range(int(input())):
    n = int(input())
    s1 = 0
    s2 = 0
    for i in range(1, n // 2):
        s1 += 2 ** i
        s2 += 2 ** (i + n//2 - 1)
    s1 += 2 ** n
    s2 += 2 ** (n - 1)



    print(s1 - s2)