import sys
range = xrange
input = raw_input

n = int(input())
A = input()
B = input()

Acount = [0]*200
Bcount = [0]*200

total = 0
for i in range(n):
    a = ord(A[i])
    b = ord(B[i])
    
    total += Bcount[a] * (n - i)
    Acount[a] += i + 1
    total += Acount[b] * (n - i)
    Bcount[b] += i + 1

print total*6.0/(n*(n + 1)*(2*n + 1))