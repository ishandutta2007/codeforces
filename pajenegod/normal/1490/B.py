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

    C = [0] * 3
    for a in A:
        C[a % 3] += 1

    goal = n // 3
    cost = 0

    while True:
        for rem in range(3):
            if C[rem] > goal:
                x = C[rem] - goal
                cost += x
                C[(rem + 1) % 3] += x
                C[rem] = goal
                break
        else:
            break
    print cost