import sys
input = sys.stdin.readline

def is_good3(A):
    return (A[0] < A[1] > A[2]) or (A[0] > A[1] < A[2])

def is_good4(A):
    if A[1] < A[0] < A[2] or A[1] > A[0] > A[2]:
        if A[1] < A[3] < A[2] or A[1] > A[3] > A[2]:
            return True
    return False


t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    ways = n + (n - 1)
    for i in range(n - 2):
        ways += is_good3(A[i:i+3])
    for i in range(n - 3):
        ways += is_good4(A[i:i+4])

    print ways