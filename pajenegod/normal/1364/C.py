import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

empty = []

big = 10**6 + 10
B = []
i = 0
counter = [0] * big
for j in range(n):
    a = A[j]
    B.append(-1)
    empty.append(j)
    
    while True:
        while counter[i]:
            i += 1
        if i == a:
            break
        if empty:
            k = empty.pop()
            B[k] = i
            counter[i] += 1
        else:
            print -1
            sys.exit()

for j in empty:
    B[j] = 10**6

print ' '.join(str(x) for x in B)