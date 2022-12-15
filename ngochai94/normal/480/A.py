cache=[]
for i  in range(input()):
    j,k=map(int,raw_input().split())
    cache.append((j,k))
tem=0
cache.sort()
for i in cache:
    j,k=i
    if k>=tem:
        tem=k
    else:
        tem=j
print tem