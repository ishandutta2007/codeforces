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
    n, = cint
    A = cint(n)

    counter = defaultdict(int)
    for a in A:
        counter[a] += 1

    buckets = [0]
    for a in counter:
        buckets.append(counter[a])
    buckets.sort()

    best = n

    count_larger = len(buckets)
    s_larger = sum(buckets)
    s_smaller = 0
    i = 0
    for g in buckets:
        while buckets[i] < g:
            s_smaller += buckets[i]
            s_larger -= buckets[i]
            count_larger -= 1
            i += 1

        best = min(best, s_smaller + s_larger - g * count_larger)

        
    print best