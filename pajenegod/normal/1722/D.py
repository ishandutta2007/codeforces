import sys

t = int(input())
for _ in range(t):
    n = int(input())
    S = input()

    A = [i - (n - 1 - i) for i in range(n)]
    val = 0
    for i in range(n):
        if S[i] == 'L':
            A[i] = -A[i]
            val += i
        else:
            val += n - 1 - i
        A[i] = max(A[i], 0)
    
    A.sort()
    out = []
    for a in A[::-1]:
        val += a
        out.append(val)
    print(*out)