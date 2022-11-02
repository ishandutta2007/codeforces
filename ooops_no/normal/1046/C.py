a,b=map(int,input().split())
l=list(map(int,input().split()))
new=list(map(int,input().split()))
number=l[b-1]+new[0]
for i in range(b-1):
    if number>=new[-1]+l[i]:
        b-=1
        del new[-1]
print(b)