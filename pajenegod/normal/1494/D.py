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


n, = cint
mat = []
for _ in range(n):
    mat += cint(n)

A = [mat[i*n+i] for i in range(n)]
sup = [-1] * n

def solve(B):
    if len(B) == 1:
        return B[0]
    
    maxi = -1
    ind = -1 
    for i in B:
        for j in B:
            if mat[i * n + j] > maxi:
                maxi = mat[i * n + j]
                ind = i
    
    
    leader = len(A)
    A.append(maxi)
    sup.append(-1)
    
    while B:
        i = B[0]

        P1 = []
        P2 = []

        for j in B:
            if j == i or mat[i * n + j] != maxi:
                P1.append(j)
            else:
                P2.append(j)
        

        sup[solve(P1)] = leader
        B = P2
    return leader


leader = solve(list(range(n)))

k = len(A)
print k
print ' '.join(str(x) for x in A)

print leader + 1
for i in range(k):
    if i != leader:
        j = sup[i]
        print i + 1, j + 1