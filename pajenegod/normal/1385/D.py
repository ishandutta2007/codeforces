import sys
range = xrange
input = raw_input

def mapper(A):
    return [ord(c) - ord('a') for c in A]
def remapper(A):
    return ''.join(chr(c + ord('a')) for c in A)

t = int(input())
for _ in range(t):
    n = int(input())
    bottom_c = n.bit_length() - 2

    A = mapper(input())

    DP = [0] * (2 * n)
    correct = [0] * (2 * n)
    for i in range(n):
        if A[i] <= bottom_c:
            correct[i + n >> bottom_c - A[i]] += 1
    
    for i in reversed(range(1, 2 * n)):
        interval_width = 1 << n.bit_length() - i.bit_length()
        if i >= n:
            c = i.bit_length() - 1
            DP[i] += A[i - n] != c
        else:
            alt1 = DP[2 * i + 1] - correct[2 * i]
            alt2 = DP[2 * i    ] - correct[2 * i + 1]
            DP[i] = min(alt1, alt2) + interval_width//2
    print DP[1]