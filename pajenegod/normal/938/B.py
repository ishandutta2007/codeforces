import sys
range = xrange
input = raw_input

n = int(input())
pre = [0]*(10**6+2)
P = [int(x) for x in input().split()]

left = 0
for p in P:
    pre[p]+=1
    left += 1
me = 1
you = 10**6
time = 0
while left>0:
    me += 1
    left-=pre[me]
    pre[me]=0
    you-=1
    left-=pre[you]
    pre[you]=0
    time+=1
print time