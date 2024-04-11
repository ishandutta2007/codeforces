import sys
range = xrange
input = raw_input

n = int(input())

big = 10**5+10
P = [1]*big
P[0] = P[1] = 0
biggest_factor = [0]*big
for i in range(big):
    if P[i]:
        biggest_factor[i] = i
        j = i + i
        while j<big:
            P[j] = 0
            biggest_factor[j] = i
            j += i

B = [0]*(n+1)
count = 1
for i in range(n+1):
    if P[i]:
        B[i] = count
        count += 1
    else:
        B[i] = B[biggest_factor[i]]

print ' '.join(str(b) for b in B[2:])