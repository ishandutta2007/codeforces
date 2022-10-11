import sys
range = xrange
input = raw_input

D = {}
D['U'] = (0,1)
D['R'] = (1,0)
D['L'] = (-1,0)
D['D'] = (0,-1)

n = int(input())
S = input()

if S[0]=='U':
    prev = 2
    pos = (0,1)
else:
    prev = 1
    pos = (1,0)

count = 0
for c in S[1:]:
    walk = D[c]

    pos = (pos[0]+walk[0],pos[1]+walk[1])

    if pos[0]==pos[1]:
        cur = prev
    elif pos[0]>pos[1]:
        cur = 1
    else:
        cur = 2

    if cur!=prev:
        count += 1
        prev = cur

print count