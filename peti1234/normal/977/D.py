n=int(input())
l=list(map(int,input().split()))
def k(a):
    d2=0
    d3=0
    while a%2==0:
        d2=d2+1
        a=a//2
    while a%3==0:
        d3=d3+1
        a=a//3
    return d2-d3
l.sort(key=k)
print(*l)