import sys, random
range = xrange
input = raw_input


def query(i, j):
    print '?', perm[i] + 1, perm[j] + 1
    sys.stdout.flush()
    return int(input())

def test(i = 0, x0 = (1 << 11) - 1, t = 30):
    for _ in range(t):
        y = random.randrange(n - 1)
        if y >= i:
            y += 1
        x0 &= query(i, y)
    return x0

n = int(input())
perm = list(range(n))
random.shuffle(perm)
invperm = [-1]*n
for i in range(n):
    invperm[perm[i]] = i

x0 = test()

i = 0
for j in range(1, n):
    ans = query(i, j)
    if (ans | x0) == x0 and ans <= x0:
        i = j
        x0 = test(i, ans, 10)

assert(x0 == 0)

# 0 found at index i

A = [-1]*n
A[i] = 0
for j in range(n):
    if i != j:
        A[j] = query(i,j)

A = [A[invperm[i]] for i in range(n)]
assert list(range(n)) == sorted(A)
print '!', ' '.join(str(x) for x in A)