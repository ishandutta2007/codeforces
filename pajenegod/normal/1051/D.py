import sys
range = xrange
input = raw_input

MOD = 998244353
MOD2 = 998244353

n,k = [int(x) for x in input().split()]


# DP[(i,K,b)) number of ways to have K components ending at index i with pattern b


#DP = di(int)
DP0 = [[0 for _ in range(2*(i+1)+3)] for i in range(n)]
DP1 = [[0 for _ in range(2*(i+1)+3)] for i in range(n)]
patterns = [0,1]
for p in patterns:
    if p==0 or p==3:
        DP0[0][1]=1
    else:
        DP1[0][2]=1

for i in range(1,n):
    D0 = DP0[i-1]
    D1 = DP1[i-1]
    E0 = DP0[i]
    E1 = DP1[i]
    for K in range(1,2*(i+1)+1):
        #ans0 = E0[K]
        #ans1 = E1[K]

        #tot = D[K-1][3] + D[K][2] + D[K][1] + D[K-1][0]

        ans0  = D0[K-1] + D1[K]   + D1[K]   + D0[K]
        ans1  = D0[K-1] + D1[K-2] + D1[K]   + D0[K-1]
        #ans[2]  = D[K-1][3] + D[K][2]   + D[K-2][1] + D[K-1][0]
        #ans[3]  = D[K][3]   + D[K][2]   + D[K][1]   + D[K-1][0]
       
        #ans[0] = tot + D[K][0]   -D[K-1][0]
        #ans[1] = tot + D[K-2][2] -D[K][2]
        #ans[2] = tot + D[K-2][2] -D[K][2]
        #ans[3] = tot + D[K][3]   -D[K-1][3]

        
        while ans0>=MOD2:
            ans0-=MOD2
        
        while ans1>=MOD2:
            ans1-=MOD2
        E0[K] = ans0
        E1[K] = ans1
        #ans[2] = ans[1]
        #ans[3] = ans[0]
        
        #while ans[2]>=MOD2:
        #    ans[2]-=MOD2
        
        #while ans[3]>=MOD2:
        #    ans[3]-=MOD2
        
        

print 2*(DP0[n-1][k]+DP1[n-1][k])%MOD
#print sum(DP[(n-1,k,p)] for p in patterns)%MOD