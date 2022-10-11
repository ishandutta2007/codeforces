import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n, k, z = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    cumsum = [0]
    for a in A:
        cumsum.append(cumsum[-1] + a)

    s = A[0]
    i = 0
    best = -1
    while i < n - 1 and k:
        c = min(k >> 1,z)
        tmp = s + A[i] * c + A[i + 1] * c
        moves_left = k - 2 * c

        low = cumsum[i + 1]
        high = cumsum[i + moves_left + 1] if i + moves_left + 1 <= n else cumsum[-1]
        tmp += high - low
        if best < tmp:
            best = tmp

        i += 1
        s += A[i]
        k -= 1
    if best < s:
        best = s
    print best