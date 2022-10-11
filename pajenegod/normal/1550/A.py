import sys
input = raw_input

t = int(input())
for _ in range(t):
    s = int(input())
    A = [1]
    s -= 1
    while s:
        A.append(min(s, A[-1] + 2))
        s -= A[-1]
    print len(A)