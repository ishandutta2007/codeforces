import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    S = input()
    A = [+(c == '+') for c in S]
    n = len(A)

    count = 0
    s = 0
    for i in range(n):
        if A[i]:
            s += 1
        else:
            if s:
                s -= 1
            else:
                count += i + 1
    print count + n