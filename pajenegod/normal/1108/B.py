import sys
range = xrange
input = raw_input
n = int(input())
D = [int(x) for x in input().split()]

counter = [0]*10**5
for d in D:
    counter[d]+=1

x = max(D)
for i in range(1,x+1):
    if x%i==0:
        counter[i]-=1

for i in range(10**5):
    if counter[i]>0:
        y = i
print x,y