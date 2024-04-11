import sys
range = xrange
input = raw_input

MOD = 10**9+7
def modinv(x):
    return pow(x,MOD-2,MOD)


n,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]


pos1 = pow(m,sum(1 for a in A if a==0),MOD)
pos2 = pow(m,sum(1 for a in B if a==0),MOD)

pos = (pos1*pos2)%MOD

free = [0]*n

if A[n-1]!=0 and B[n-1]!=0:
#    equal[n-1] = int(A[n-1]==B[n-1])
    free[n-1] = 1
elif A[n-1]!=0:
#    equal[n-1] = 1
    free[n-1] = m
elif B[n-1]!=0:
#    equal[n-1] = 1
    free[n-1] = m
else:
#    equal[n-1] = m
    free[n-1] = (m*m)%MOD


for i in range(n-2,-1,-1):
    if A[i]!=0 and B[i]!=0:
#        equal[i] = equal[i+1]*int(A[i]==B[i])
        free[i] = free[i+1]
    elif A[i]!=0:
#        equal[i] = equal[i+1]
        free[i] = free[i+1]*m
    elif B[i]!=0:
#        equal[i] = equal[i+1]
        free[i] = free[i+1]*m
    else:
#        equal[i] = equal[i+1]*m
        free[i] = free[i+1]*m*m
#    equal[i]%=MOD
    free[i]%=MOD

equal = [0]*n

if A[0]!=0 and B[0]!=0:
    equal[0] = int(A[0]==B[0])
elif A[0]!=0:
    equal[0] = 1
elif B[0]!=0:
    equal[0] = 1
else:
    equal[0] = m


for i in range(1,n):
    if A[i]!=0 and B[i]!=0:
        equal[i] = equal[i-1]*int(A[i]==B[i])
    elif A[i]!=0:
        equal[i] = equal[i-1]
    elif B[i]!=0:
        equal[i] = equal[i-1]
    else:
        equal[i] = equal[i-1]*m
    equal[i]%=MOD

leq = [0]*n
i = n-1
if A[i]!=0 and B[i]!=0:
    if A[i]==B[i]:
        leq[i] = 1
    elif A[i]>B[i]:
        leq[i] = 1
    else:
        leq[i] = 0
elif A[i]!=0:
    # Pick B[i]=A[i]
    leq[i] = 1
    # Pick A[i]>B[i]
    leq[i] += (A[i]-1)
elif B[i]!=0:
    # Pick B[i]=A[i]
    leq[i] = 1
    # Pick A[i]>B[i]
    leq[i] += (m-B[i]) 
else:
    # Pick A[i]=B[i]
    leq[i] = m
    # Pick A[i]>B[i]
    leq[i] += (m*(m-1))//2
for i in range(n-2,-1,-1):
    if A[i]!=0 and B[i]!=0:
        if A[i]==B[i]:
            leq[i] = leq[i+1]
        elif A[i]>B[i]:
            leq[i] = free[i+1]
        else:
            leq[i] = 0

    elif A[i]!=0:
        # Pick B[i]=A[i]
        leq[i] = leq[i+1]
        # Pick A[i]>B[i]
        leq[i] += (A[i]-1)*free[i+1]
    elif B[i]!=0:
        # Pick B[i]=A[i]
        leq[i] = leq[i+1]
        # Pick A[i]>B[i]
        leq[i] += (m-B[i])*free[i+1] 
    else:
        # Pick A[i]=B[i]
        leq[i] = m*leq[i+1]
        # Pick A[i]>B[i]
        leq[i] += (m*(m-1))//2*free[i+1]
    leq[i] %= MOD
print ((leq[0]-equal[n-1])*modinv(pos))%MOD

#waysleq = [0]*n
#waysl = [0]*n
#
#duper = (m*(m-1))//2
#
#if A[n-1]!=0 and B[n-1]!=0:
#    waysleq[n-1] = int(A[n-1]>=B[n-1])
#    waysl[n-1] = int(A[n-1]>B[n-1])
#elif A[n-1]!=0:
#    waysleq[n-1] = A[n-1]
#    waysl[n-1] = A[n-1]-1
#elif B[n-1]!=0:
#    waysleq[n-1] = m-B[n-1]+1
#    waysl[n-1] = m-B[n-1]
#else:
#    waysleq[n-1] = duper+m
#    waysl[n-1] = duper
#
#for i in range(n-2,-1,-1):
#    if A[i]!=0 and B[i]!=0:
#    
#        waysleq[i] = int(A[n-1]>=B[n-1])
#        waysl[i]   = int(A[n-1]>B[n-1])
#    
#    elif A[n-1]!=0:
#        waysleq[n-1] = A[n-1]
#        waysl[n-1] = A[n-1]-1
#    elif B[n-1]!=0:
#        waysleq[n-1] = m-B[n-1]+1
#        waysl[n-1] = m-B[n-1]
#    else:
#        waysleq[n-1] = duper+m
#        waysl[n-1] = duper