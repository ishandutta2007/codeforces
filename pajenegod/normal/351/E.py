import sys
range = xrange
input = raw_input

n = int(input())
A = [abs(int(x)) for x in input().split()]

val = 0

for a in sorted(set(A)):
    DP = [0]
    for i in range(n):
        if A[i] == a:
            # positive
            base  = sum(1 for j in range(i + 1, n) if A[j] < A[i])
            # negative
            base2 = sum(1 for j in range(i) if A[j] < A[i])
            k = len(DP)
            DP.append(DP[-1] + base)
            for j in reversed(range(k)):
                DP[j] = min(DP[j] + base2 + j, DP[j - 1] + base)
    val += min(DP)
print val