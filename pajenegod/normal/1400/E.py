import sys
range = xrange
input = raw_input

#def solve(A, b):
#    n = j = len(A)
#    if n == 0:
#        return 0
#    a = min(A)
#    s = a - b
#    for i in reversed(range(n)):
#        if A[i] == a:
#            s += solve(A[i + 1:j], a)
#            j = i
#    s += solve(A[0:j], a)
#    return min(n, s)

n = int(input())
A = [int(x) for x in input().split()]

arrays = [A]
B = [0]
stack = [0]
ans = [0]

while stack:
    state = stack.pop()
    if state >= 0:
        A = arrays[state]
        b = B[state]
        
        n = j = len(A)
        if n == 0:
            continue
        
        a = min(A)
        
        stack.append(~state)
        ans.append(a - b)
        for i in reversed(range(n)):
            if A[i] == a:
                stack.append(len(arrays))
                arrays.append(A[i + 1:j])
                B.append(a)
                j = i
        
        stack.append(len(arrays))
        arrays.append(A[0:j])
        B.append(a)
    else:
        s = ans.pop()
        ans[-1] += min(s, len(arrays[~state]))

print ans[0]