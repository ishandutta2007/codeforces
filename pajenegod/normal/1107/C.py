import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

seq = input()

dmg = 0

i = 0
while i<n:
    cur = seq[i]
    j = i
    while j<n and seq[j]==cur:j+=1
    
    dmg += sum(sorted(A[i:j],reverse=True)[:k])
    i = j
print dmg