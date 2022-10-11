import sys
input = raw_input

t = int(input())
for _ in range(t):
    n = input()
    n1 = int('0' + n[0::2])
    n2 = int('0' + n[1::2])

    print (n1 + 1) * (n2 + 1) -2 #+ ((n1 & 1) == (n2 & 1) == 0) - 2