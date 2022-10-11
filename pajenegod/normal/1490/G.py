import inspect
import dis
import sys

def expecting():
    """Return how many values the caller is expecting"""
    f = inspect.currentframe().f_back.f_back
    return ord(f.f_code.co_code[f.f_lasti + 1])

inp = sys.stdin.read().split()
inp.reverse()

class cint:
    def __iter__(self):
        for i in range(expecting()):
            yield int(inp.pop())
    def __call__(self, n=-1):
        if n == -1:
            return int(inp.pop())
        return [int(inp.pop()) for _ in range(n)]

cint = cint()

class cin:
    def __iter__(self):
        for i in range(expecting()):
            yield inp.pop()
    def __call__(self, n=-1):
        if n == -1:
            return inp.pop()
        return [inp.pop() for _ in range(n)]

cin = cin()


from collections import defaultdict

t, = cint
for _ in range(t):
    n,m = cint
    A = cint(n)
    X = cint(m)

    cumA = [0]
    for a in A:
        cumA.append(cumA[-1] + a)

    maxpoint = max(cumA)
    total = cumA[-1]

    ans = [0] * m

    for qind in range(m):
        x = X[qind]
        if total > 0 and x > maxpoint:
            full_rounds = (x - maxpoint + total - 1) // total
            X[qind] -= full_rounds * total
            ans[qind] += full_rounds * n

    i = 0
    for qind in sorted(range(m), key = X.__getitem__):
        x = X[qind]
        while i <= n and cumA[i] < x:
            i += 1

        if i == n + 1:
            ans[qind] = -1
        else:
            ans[qind] += i - 1

    print ' '.join(str(x) for x in ans)