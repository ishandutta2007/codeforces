import sys
range = xrange
input = raw_input

n = int(input())
A = [c=='1' for c in input()]

pos = True
for i in range(n):
    if not A[i]:
        continue
    if i>0 and A[i-1]:
        pos = False
    if i<n-1 and A[i+1]:
        pos = False
for i in range(n):
    if A[i]:
        continue
    if (i==0 or not A[i-1]) and (i==n-1 or not A[i+1]):
        pos = False
if pos:
    print 'Yes'
else:
    print 'No'