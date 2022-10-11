import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
t = inp[ii]; ii += 1
out = []
for _ in range(t):  
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    ans = 0
    i = 0
    while i < n:
        j = i
        sign = 1 if A[i] > 0 else -1
        while j < n and A[j] * sign > 0:
            j += 1

        ans += max(A[i:j])
        i = j
    out.append(str(ans))

print '\n'.join(out)