import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

L = [0]*n
R = [0]*n

stack = []
for i in range(n):
    while stack and A[stack[-1]] < A[i]:
        stack.pop()
    L[i] = stack[-1] if stack else -1
    stack.append(i)

stack = []
for i in reversed(range(n)):
    while stack and A[stack[-1]] <= A[i]:
        stack.pop()
    R[i] = stack[-1] if stack else n
    stack.append(i)

L2 = [0]*n
R2 = [0]*n

last = [-1]*30
for i in range(n):
    x = -1

    a = A[i]
    j = 0
    while a:
        if a&1:
            last[j] = i
        elif last[j] > x:
            x = last[j]
        
        j += 1
        a >>= 1
    L2[i] = x


last = [n]*30
for i in reversed(range(n)):
    x = n

    a = A[i]
    j = 0
    while a:
        if a&1:
            last[j] = i
        elif last[j] < x:
            x = last[j]

        j += 1
        a >>= 1
    R2[i] = x

for i in range(n):
    L2[i] = max(L[i], L2[i])
    R2[i] = min(R[i], R2[i])
    #if L2[i] == -1:
    #    L2[i] = L[i]
    #if R2[i] == n:
    #    R2[i] = R[i]
ans = 0
for i in range(n):
    # l in (L[i], L2[i]], r in [i,R[i])
    # l in (L[i], i], r in [R2[i], R[i])

    # l in (L[i], L2[i]], r in [R2[i], R[i])

    ans += (L2[i] - L[i]) * (R[i] - i) + (i - L[i]) * (R[i] - R2[i]) - (L2[i] - L[i]) * (R[i] - R2[i])

print ans