import sys
range = xrange
input = raw_input

n = int(input())

A = [int(x)&1 for x in input().split()]

buckets = []
i = 0
while i < n:
    j = i
    while j < n and A[i] == A[j]:
        j += 1

    buckets.append(j - i)
    i = j

stack = []
for b in buckets:
    stack.append(b&1)
    while len(stack) >= 3 and (
          stack[~2] == stack[~1] == stack[~0] == 0 or 
          stack[~2] == stack[~1]^1 == stack[~0] == 1
          ):
              stack.pop()
              stack.pop()
              stack.pop()
              stack.append(0)

print 'YES' if sum(stack)<=1 else 'NO'