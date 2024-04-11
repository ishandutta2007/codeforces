y,b,r=map(int,input().split())
for i in range(100,0,-1):
    if i<=r-2 and i<=y and i<=b-1:
        print(i*3+3)
        break