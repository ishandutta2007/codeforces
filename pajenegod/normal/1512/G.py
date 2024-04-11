import sys, os
range = xrange

big = 10**7 + 10

def solve():
    summer = [1] * big
    for i in range(2, big):
        j = i
        while j < big:
            summer[j] += i
            j += i
    return summer

summer = solve()

mapper = [-1] * big
for i in reversed(range(1, big)):
    if summer[i] < big:
        mapper[summer[i]] = i

inp = [int(x) for x in sys.stdin.read().split()]
os.write(1, '\n'.join(str(mapper[c]) for c in inp[1:]))