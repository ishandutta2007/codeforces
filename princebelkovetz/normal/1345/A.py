#from sys import stdin, stdout, setrecursionlimit
#input = stdin.readline
#print = stdout.write
for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = 'NO'
    if n == 1 or m == 1 or (n == 2 and m == 2):
        ans = 'YES'
    print(ans)