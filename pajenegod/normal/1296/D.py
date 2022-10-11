import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
a = inp[ii]; ii += 1
b = inp[ii]; ii += 1
k = inp[ii]; ii += 1

H = inp[ii: ii + n]; ii += n

H = [(h - 1) % (a + b) + 1 for h in H]

H.sort()

score = 0
for h in H:
    if k >= (h - 1) // a:
        k -= (h - 1) // a
        score += 1
print score