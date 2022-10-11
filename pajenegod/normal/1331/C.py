import sys
range = xrange
input = raw_input

A = 'and they lived happily ever after'.split()
B = 'and after happily lived ever they'.split()

n = int(input())

s = [int(x) for x in bin(n + 64)[3:]]
t = [0]*6
for i in range(6):
    if s[i]:
        t[B.index(A[i])] = 1

print int(''.join(str(x) for x in t) , 2)