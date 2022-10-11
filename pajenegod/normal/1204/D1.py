import sys
range = xrange
input = raw_input

B = [int(x) for x in input()]
n = len(B)

sumB = sum(B)
if sumB == n or sumB == 0:
    print '0'*n
    sys.exit()

cur = 0
D = []
for i in reversed(range(n)):
    D.append(cur)
    if B[i] == 0:
        cur += 1
    else:
        cur -= 1
        if cur < 0:
            cur = 0

D = D[::-1]

for i in range(n):
    if B[i] == 1 and D[i] == 0:
        B[i] = 0
print ''.join(str(x) for x in B)