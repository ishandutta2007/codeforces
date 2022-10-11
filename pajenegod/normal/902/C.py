def tree(h,a,special=False):
    ind = 0

    parent = [-1]*sum(a)
    bottom = []
    for i in range(a[-1]):
        bottom.append(ind)
        ind+=1
    prev = bottom
    for y in range(h-1,-1,-1):
        root = ind
        ind+=1
        if special and a[y]>1 and a[y+1]>1: 
            for node in prev[1:]:
                parent[node]=root
            parent[prev[0]]=root+1
            special = False
        else:
            for node in prev:
                parent[node]=root
        nextlayer = [root]
        for i in range(a[y]-1):
            nextlayer.append(ind)
            ind+=1
        prev = nextlayer
    return parent,special

h=int(input())
a = [int(x) for x in input().split()]

p1,special = tree(h,a)
p2,special =tree(h,a,special=True)
if not special:
    print('ambiguous')
    print(*[x+1 for x in p1])
    print(*[x+1 for x in p2])
else:
    print('perfect')