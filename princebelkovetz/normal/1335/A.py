from sys import stdin, stdout
input=stdin.readline
print=stdout.write
for _ in range(int(input())):
    n=int(input())
    if n==1 or n==2:
        print('0\n')
    elif n%2==0:
        print(str(n//2-1))
        print('\n')
    else:
        print(str(n//2))
        print('\n')