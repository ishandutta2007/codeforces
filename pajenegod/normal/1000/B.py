import sys
range = xrange
input = sys.stdin.readline

n,M = [int(x) for x in input().split()]

n+=1
A = [0]+[int(x) for x in input().split()]

normal = []
state = []
val = 0
on = False
last_switch = 0
for i in range(n):
    if on:
        val += A[i]-last_switch
        last_switch = A[i]
        on = False
    else:
        on = True
        last_switch = A[i]
    normal.append(val)
    state.append(on)
        
if on:
    val += M-last_switch
normal.append(val)
state.append(False)


rnormal = []
rstate = []
val = 0
on = True
last_switch = 0
for i in range(n):
    if on:
        val += A[i]-last_switch
        last_switch = A[i]
        on = False
    else:
        on = True
        last_switch = A[i]
    rnormal.append(val)
    rstate.append(on)

if on:
    val += M-last_switch
rnormal.append(val)
rstate.append(False)

opt_val = normal[-1]
for i in range(n):
    if (i==n-1 or A[i]+1!=A[i+1]) and A[i]+1!=M and not state[i]:
        val = normal[i] + rnormal[-1]-rnormal[i]-1
        if val>opt_val:
            opt_val = val

print opt_val