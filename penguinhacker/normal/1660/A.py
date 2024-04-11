t=int(input())
for _ in range(t):
    a, b=map(int, input().split())
    if a==0:
        print(1)
    else:
        print(a+2*b+1)