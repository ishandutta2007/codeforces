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
    n,u,r,d,l = cint


    for a1 in 0,1:
        for a2 in 0,1:
            for a3 in 0,1:
                for a4 in 0,1:
                    U,R,D,L = u,r,d,l       
                    
                    U -= a1
                    R -= a1

                    R -= a2
                    D -= a2

                    D -= a3
                    L -= a3

                    L -= a4
                    U -= a4

                    if U < 0 or R < 0 or D < 0 or L < 0:
                        continue
                    if U > n - 2 or R > n - 2 or D > n - 2 or L > n - 2:
                        continue
                    print 'YES'
                    break
                else:
                    continue
                break
            else:
                continue
            break
        else:
            continue
        break
    else:
        print 'NO'