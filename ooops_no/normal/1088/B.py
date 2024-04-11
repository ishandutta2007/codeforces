n,k=map(int,input().split())
list=sorted(list(map(int,input().split())))
dele=0
counter=0
plus=0
if n==1:
    print(list[0])
    for _ in range(1,k):
        print(0)
else:
    for _ in range(k):
        print(list[counter]-dele)
        dele+=list[counter]-dele
        counter+=1
        while counter<n-1 and list[counter]==dele:
            counter+=1
            plus+=1
        if counter>=n-1:
            break
    if _!=k-1:
        print(list[counter]-dele)
    for __ in range(_+2,k):
        print(0)