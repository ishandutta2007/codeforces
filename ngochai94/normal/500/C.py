n,m=map(int,raw_input().split())
wei=map(int,raw_input().split())
order=map(int,raw_input().split())
orderrev=order[::-1]
sta=[i for i in range(1,n+1)]
for i in orderrev:
    ind=sta.index(i)
    sta.pop(ind)
    sta.append(i)
ans=0
for i in order:
    ind=0
    while sta[ind]!=i:
        ind+=1
    for j in range(ind+1,n):
        ans+=wei[sta[j]-1]
    sta.pop(ind)
    sta.append(i)
print ans