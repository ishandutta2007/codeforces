import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

def solve(A, k, m):
    n = len(A)
    i = 0
    while A[i] != -1:
        i += 1
    if i == n - 1:
        return 0
    
    if i + 1 >= n - k:
        return 0
    mini = min(A[-k - 1:])
    j = n - 1
    while A[j] != mini:
        j -= 1
    
    A[j] = 10**9 + 1
    k += m // 2
    return mini + solve(A, k, m // 2)

print solve(A, 0, n)