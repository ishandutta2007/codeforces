import sys
range = xrange
input = raw_input

x = int(input())

M = []

t = 0
while bin(x).count('0')>1:
    i = 1
    binx = bin(x)
    while binx[i]!='0':
        i += 1

    ni = len(binx) - i
    M.append(ni)
    x ^= 2**ni - 1
    t += 1

    if bin(x).count('0')>1:
        x += 1
        t += 1
print t
print ' '.join(str(ni) for ni in M)