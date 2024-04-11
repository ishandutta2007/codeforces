import sys

def xor(A):
    val = 0
    for a in A:
        val ^= a
    return val

t = int(input())
for _ in range(t):
    n = int(input())
    A = list(range(n - 1))

    a_even = xor(A[::2])
    a_odd = xor(A[1::2])

    x = a_even ^ a_odd
    A[x == 0] += 2**29
    A.append(x + 2**29)

    assert xor(A[::2]) == xor(A[1::2]) and len(set(A)) == n
    print(*A)