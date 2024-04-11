t=int(input())
for i in range(t):
    a=int(input())
    b=100
    if (a%2==0):
        a/=2
        b/=2
    if (a%2==0):
        a/=2
        b/=2
    if (a%5==0):
        a/=5
        b/=5
    if (a%5==0):
        a/=5
        b/=5
    print(int(b))