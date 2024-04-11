import sys
from collections import deque
range = xrange
input = sys.stdin.readline

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

Q = deque(A)

while Q and Q[0]<=k:Q.popleft()
while Q and Q[-1]<=k:Q.pop()

print n-len(Q)