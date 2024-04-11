import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [+(')' == c) for c in input()]

    stack = []
    for a in A:
        if a == 1 and stack and stack[-1] == 0:
            stack.pop()
        else:
            stack.append(a)
    print len(stack) // 2