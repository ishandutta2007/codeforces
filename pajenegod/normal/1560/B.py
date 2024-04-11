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
    a,b,c = [int(x) - 1 for x in input().split()]

    nhalf = abs(b - a)

    if a >= nhalf * 2 or b >= nhalf * 2 or c >= nhalf * 2:
        print -1
        continue

    print (c - nhalf) % (2 * nhalf) + 1