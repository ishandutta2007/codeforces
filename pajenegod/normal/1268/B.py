import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

stack = [0]
for x in reversed(A):
    if stack[-1] & 1 != x & 1:
        stack.append(len(stack))
    elif len(stack) > 1:
        stack.pop()

print (sum(A) - len(stack)//2)//2