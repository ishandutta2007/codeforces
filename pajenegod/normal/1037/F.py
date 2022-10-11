import sys
range = xrange
input = raw_input

def z(A, k):
    if len(A) < k:
        return 0
    B = [max(A[i:i+k]) for i in range(len(A) - k + 1)]
    return sum(B) + z(B, k)

def f(n):
    return n * (n - 1) >> 1

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

prev = []
stack = [-1]
for i in range(n):
    while len(stack) > 1 and A[stack[-1]] <= A[i]:
        stack.pop()
    prev.append(stack[-1])
    stack.append(i)

nesta = []
stack = [n]
for i in reversed(range(n)):
    while len(stack) > 1 and A[stack[-1]] < A[i]:
        stack.pop()
    nesta.append(stack[-1])
    stack.append(i)
nesta.reverse()

ans = 0
for i in range(n):
    x = prev[i] + 1
    a = b = i - x
    c = nesta[i] - 1 - x
    
    y = 0

    a = max(0, a - (k - 1))
    c -= k - 1
    b = min(b, c)
    if a > b:
        continue

    y += f(a // (k - 1)) * (k - 1)
    y -= a % (k - 1) + a * (a // (k - 1))
    
    extra = (c - b + k - 2) // (k - 1)
    y += (b + 1) * extra
    c -= (k - 1) * extra

    times = c // (k - 1) + 1
    y += (c + 1) * times
    y -= f(times) * (k - 1)
    
    ans += y * A[i]

print ans % (10**9 + 7)