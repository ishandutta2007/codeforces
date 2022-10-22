from sys import stdin, stdout
input=stdin.readline
print=stdout.write
for _ in range(int(input())):
    x, n, m = map (int, input().split())
    while x>=21 and n>0:
        x//=2
        x+=10
        n-=1
    if x > 10*m:
        print('NO\n')
    else:
        print('YES\n')