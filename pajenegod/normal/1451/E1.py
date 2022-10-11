import sys,os
range = xrange
input = raw_input

def query(i,j,c):
    os.write(1, '%s %d %d\n' % (c, i + 1, j + 1))
    return int(sys.stdin.readline())

n = int(input())

XOR = [0]
for j in range(1, n):
    XOR.append(query(0,j,'XOR'))

def solve(XOR, masker):
    seen = set()
    for j in range(n):
        if XOR[j] in seen:
            i = XOR.index(XOR[j])
            val = masker(query(i,j,'OR')) ^ XOR[j]
            break
        else:
            seen.add(XOR[j])
    return [val ^ x for x in XOR]

masker = lambda x: x & 1
A1 = solve([masker(x) for x in XOR], masker)
masker = lambda x: x >> 1
A2 = solve([masker(x) for x in XOR], masker)

A = [A1[i] + (A2[i] << 1) for i in range(n)]

print '!', ' '.join(str(x) for x in A)