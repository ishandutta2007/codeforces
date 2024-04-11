from sys import stdin, stdout
input=stdin.readline
print=stdout.write
for _ in range(int(input())):
    n, m, x = map(int, input().split())
    ans=[]
    for i in range(97, 97+x):
        ans.append(chr(i))
    ans *= n // x + 1
    for i in range(n):
        print(ans[i])
    print('\n')