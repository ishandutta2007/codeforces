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




t, = cint
for _ in range(t):
    n, = cint
    A = cint(n)

    order = sorted(range(n), key = A.__getitem__)
    found = [0] * n
    winners = []

    s = 0
    j = 0
    for i in order:
        if not found[i]:
            s += A[i]
            found[i] = 1
            if order[j] == i:
                j += 1
        while j < n and A[order[j]] <= s:
            s += A[order[j]]
            found[order[j]] = 1
            j += 1

        if j == n:
            winners.append(i)
    winners.sort()

    print len(winners)
    print ' '.join(str(x + 1) for x in winners)