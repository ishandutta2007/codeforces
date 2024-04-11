import sys

n = input()
a = map(int, sys.stdin.readline().split())

stack = []

for z in a:
    stack.append(z)
    while len(stack) > 1 and stack[len(stack)-2] == stack[len(stack)-1]:
        tmp = stack[len(stack)-2]
        del stack[-1]
        del stack[-1]
        stack.append(tmp+1)

print len(stack)

for z in stack:
    print z,