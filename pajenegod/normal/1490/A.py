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

    count = 0
    for i in range(n - 1):
        a1 = A[i]
        a2 = A[i + 1]

        if a1 > a2:
            a1,a2 = a2,a1

        while 2 * a1 < a2:
            a1 *= 2
            count += 1
    print count