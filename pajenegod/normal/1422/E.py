import sys
range = xrange
input = raw_input

def mapper(S):
    return [ord(c) for c in S]

S = input()
A = mapper(S)
n = len(A)
A.append(-1)

ans = []

active = n
before_active = -1
stack = []


prev = 0
for i in reversed(range(n)):
    if prev:
        if A[i] == A[i + 1] > A[active] or (active < n and A[i] == A[i + 1] == A[active] > before_active):
            stack.pop() # i + 1
            prev = 0
        else:
            if A[i + 1] != A[active]:
                active = i + 1
                before_active = stack[-2] if len(stack) > 1 else -1
            stack.append(A[i])
            prev = 1
    else:
        prev = 1
        stack.append(A[i])
    
    
    if len(stack) <= 10:
        B = ''.join(chr(c) for c in stack)
    else:
        B = ''.join(chr(c) for c in stack[:2]) + '...' + \
            ''.join(chr(c) for c in stack[-5:])

    ans.append('%d %s' % (len(stack), B[::-1]))
print '\n'.join(str(x) for x in ans[::-1])