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

    A = [a - 1 for a in A]

    D = [-1] * n

    def solution(Ainds, count):
        if not Ainds:
            return
        ai = max(Ainds, key = A.__getitem__)
        D[ai] = count

        ind = Ainds.index(ai)
        solution(Ainds[:ind    ], count + 1)
        solution(Ainds[ind + 1:], count + 1)

    solution(list(range(n)), 0)

    print ' '.join(str(x) for x in D)