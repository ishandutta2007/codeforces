import sys
range = xrange
input  = raw_input

MOD = 10**9+7

n,l,r = [int(x) for x in input().split()]
r += 1

numbs_rem = [0,0,0]
while (r-l)%3!=0:
    numbs_rem[l%3]+=1
    l+=1
numbs_rem = [(x + (r-l)//3)%MOD for x in numbs_rem]

DP = [1,0,0]
for i in range(n):
    DP = [sum(DP[i]*numbs_rem[(3-i+j)%3] for i in range(3))%MOD for j in range(3)]

print DP[0]%MOD