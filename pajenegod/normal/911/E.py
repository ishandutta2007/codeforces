import sys
n,k = [int(x) for x in input().split()]
a = list(reversed([int(x)-1 for x in input().split()]))
s = []
b = []
goal = 0

used = [False]*(n)
for node in a:
    used[node]=True

search_from = -1
big = n-1 
res = []
while goal!=n:
    while a:
        res.append(a[-1])
        s.append(a.pop())
        search_from = s[-1]-1
        if (len(s)>1 and s[-1]>s[-2]):
            print(-1)
            sys.exit()
        while s and s[-1]==goal:
            goal += 1
            s.pop()
            if s:
                search_from = s[-1]-1
    if goal==n:
        break
    if len(s)==0:
        while big>=0 and used[big]:
            big-=1
        if big==-1:
            print(-1)
            sys.exit()
        used[big]=True
        a.append(big)
    else:
        while search_from>=0 and used[search_from]:
            search_from-=1
        if search_from==-1:
            print(-1)
            sys.exit()
        used[search_from]=True
        a.append(search_from)
        
print(*[x+1 for x in res])