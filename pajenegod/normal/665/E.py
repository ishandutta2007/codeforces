import sys
range = xrange
input = raw_input

L = [-1, -1]
count = [0,0]
def check(i):
    if L[i] == -1:
        L[i] = len(L)
        L.append(-1)
        L.append(-1)
        count.append(0)
        count.append(0)

def add(x, i = 0, bits = 30):
    count[i] += 1
    for bit in reversed(range(bits)):
        check(i)
        i = L[i] ^ (x >> bit & 1)
        count[i] += 1

# count (y xor x) > k
def get_count(x, k, i = 0, bits = 30):
    ret = 0
    for bit in reversed(range(bits)):
        i = L[i] ^ (x >> bit & 1) ^ (k >> bit & 1)
        if i < 0:
            return ret
        if k >> bit & 1 == 0:
           ret += count[i ^ 1] 
    return ret

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
k = inp[ii] - 1; ii += 1

A = inp[ii:ii + n]; ii += n

xor = [0]
for a in A:
    xor.append(xor[-1] ^ a)
xor.sort()

ans = 0
for x in xor:
    add(x)
    ans += get_count(x, k)
print ans