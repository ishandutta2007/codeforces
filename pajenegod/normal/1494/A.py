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
 
 
t, = cint
for _ in range(t):
    A = [ord(c) - ord('A') for c in cin()]
    for a in 0,1:
        for b in 0,1:
            for c in 0,1:
                B = [a,b,c]
                S = []
                for x in A:
                    if B[x]:
                        if not S:
                            break
                        else:
                            S.pop()
                    else:
                        S.append(1)
                else:
                    if not S:
                        print 'YES'
                        break
            else:
                continue
            break
        else:
            continue
        break
    else:
        print 'NO'
        continue