import sys
range = xrange
input = raw_input

n = int(input())

color1 = 0
stack1 = []
stack2 = []

color = [0]*n
for i,c in enumerate(input()):
    
    if stack1 and c == ')':
        stack1.pop()
        color[i] = color1
    else:
        stack2.append('(')
        color[i] = 1 - color1

    if len(stack1)<len(stack2):
        stack1, stack2 = stack2, stack1
        color1 = 1 - color1

print ''.join(str(x) for x in color)