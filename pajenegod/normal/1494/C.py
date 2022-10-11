import inspect
import dis
import sys
range = xrange
 
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
 
def solve(A,B):
    Bset = set(B)
    besta = points = sum(1 for a in A if a in Bset)
    

    i = j = k = 0
    while k < len(B):
        b = B[k]
        k += 1
        
        while i < len(A) and A[i] <= b:
            points -= (A[i] in Bset)
            i += 1
        

        while j < len(B) and B[j] <= b - i:
            j += 1

        besta = max(besta, k - j + points)

    return besta

t, = cint
for _ in range(t):
    n,m = cint
    A = cint(n)
    B = cint(m)

    print solve([a for a in A if a > 0], [b for b in B if b > 0]) + solve([-a for a in A[::-1] if a < 0], [-b for b in B[::-1] if b < 0])