import math

n = int(raw_input())

ans = []

a = 0
A = 1
while (1):
    if  n < A - 1:
        break

    if  a == 0:
        L, R = 1, 4 * int(math.sqrt(n))
        while L != R - 1:
            M = (L + R) / 2
            if  M * (M - 1) / 2 <= n:
                L = M
            else:
                R = M

        if  L * (L - 1) / 2 == n and L % 2 == 1:
            ans.append(L)
    else:
        L, R = 1, 4 * int(math.sqrt(n))
        while L != R - 1:
            M = (L + R) / 2
            if  M * (A - 1) + M * (M - 1) / 2 <= n:
                L = M
            else:
                R = M

        if  L * (A - 1) + L * (L - 1) / 2 == n and L % 2 == 1:
            ans.append(A * L)

    A *= 2
    a = a + 1

ans.sort()

if  len(ans) == 0:
    print "-1"
else:
    for i in xrange(len(ans)):
        if  i == 0 or ans[i] != ans[i - 1]:
            print ans[i]