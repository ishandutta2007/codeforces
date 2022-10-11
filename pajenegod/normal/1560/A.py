import sys
input = raw_input

A = []
i = 1
while len(A) < 1000:
    if i % 3 != 0 and i % 10 != 3:
        A.append(i)
    i += 1

t = int(input())
for _ in range(t):
    k = int(input())
    print A[k - 1]