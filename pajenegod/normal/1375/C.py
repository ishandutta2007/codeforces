import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    
    stack = [A[0]]
    for i in range(1, n):
        a = A[i]
        if a <= stack[-1]:
            stack.append(a)
        else:
            while len(stack) > 1 and stack[-1] < a:
                stack.pop()
            if len(stack) == 1 and stack[-1] < a:
                pass
            else:
                stack.append(a)
    if len(stack) == 1 or (len(stack) == 2 and stack[0] < stack[1]):
        print 'Yes'
    else:
        print 'No'