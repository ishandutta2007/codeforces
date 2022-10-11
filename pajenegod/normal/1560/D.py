import sys
input = raw_input

pow2 = [1 << i for i in range(62)]

def mapper(S):
    return [ord(c) - ord('0') for c in S]

pow2s = [mapper(str(n)) for n in pow2]


def solve(A, B):
    n = len(A)
    m = len(B)
    matches = 0
    j = 0
    for a in A:
        while j < m and B[j] != a:
            j += 1
        if j >= m:
            matches -= 1
        else:
            matches += 1
        j += 1
    return m - matches

t = int(input())
for _ in range(t):
    n = int(input())
    ns = mapper(str(n))

    print min(solve(S, ns) for S in pow2s)