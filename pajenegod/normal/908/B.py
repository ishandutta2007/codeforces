from collections import defaultdict as di
n,m = [int(x) for x in input().split()]
free = di(lambda:False)
startpos = (-1,-1)
goal = (-1,-1)
for y in range(n):
    s = input()
    for x in range(m):
        c = s[x]
        if c=='S':
            startpos=(x,y)
            free[(x,y)]=True
        elif c=='E':
            goal=(x,y)
            free[(x,y)]=True
        elif c=='.':
            free[(x,y)]=True
counts = 0
dire = '0123'
command = input()
for up in dire:
    for down in dire:
        for right in dire:
            for left in dire:
                if len(set([up,down,left,right]))<4:
                    continue
                pos = startpos
                for c in command:
                    x,y = pos
                    if c == up:
                        y+=1
                    elif c == down:
                        y-=1
                    elif c==right:
                        x+=1
                    else:
                        x-=1
                    pos = (x,y)
                    if pos == goal:
                        counts += 1
                        break
                    if not free[pos]:
                        break

print(counts)