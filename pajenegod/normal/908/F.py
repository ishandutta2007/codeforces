import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

n = int(inp[ii]); ii += 1
pos = []
color = []
costs = 0
reds = []
greens = []
blues = []
for i in range(n):
    a = inp[ii]; ii += 1
    b = inp[ii]; ii += 1
    pos.append(int(a))
    color.append(b)
    if b=='R':
        reds.append(i)
    elif b=='G':
        greens.append(i)
    else:
        blues.append(i)
 
if len(greens)==0:
    if len(reds)>0:
        a = reds[0]
        b = reds[-1]
        costs += pos[b] - pos[a]
    
    if len(blues)>0:
        a = blues[0]
        b = blues[-1]
        costs += pos[b] - pos[a]
    print(costs)
    sys.exit()
 
 
first_g = greens[0]
last_g = greens[-1]
if len(blues)>0 and blues[0]<=first_g:
    costs += pos[first_g] - pos[blues[0]]
if len(reds)>0 and reds[0]<=first_g:
    costs += pos[first_g] - pos[reds[0]]
 
if len(blues)>0 and blues[-1]>= last_g:
    costs += pos[blues[-1]] - pos[last_g]
if len(reds)>0  and reds[-1] >= last_g:
    costs += pos[reds[-1]]  - pos[last_g]
 
i = first_g
while True: 
    j = i+1
    REDS = [i]
    BLUES = [i]
    while j<n and color[j]!='G':
        if color[j]=='R':
            REDS.append(j)
        else:
            BLUES.append(j)
        j+=1
    if j>=n:
        break
    REDS.append(j)
    BLUES.append(j)
    best_r = 0
    for ind in range(len(REDS)-1):
        a = REDS[ind]
        b = REDS[ind+1]
        best_r = max(best_r,pos[b]-pos[a])
    best_b = 0
    for ind in range(len(BLUES)-1):
        a = BLUES[ind]
        b = BLUES[ind+1]
        best_b = max(best_b,pos[b]-pos[a])
    costs += min(2*(pos[j]-pos[i]), 3*(pos[j]-pos[i])-best_r-best_b)
 
 
    i = j
print(costs)