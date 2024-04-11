ans=0
for _ in range(input()):
    x,y=map(int,raw_input().split())
    if x<=y-2:
        ans+=1
print ans