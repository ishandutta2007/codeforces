### FASTIO
import sys, __pypy__, os, atexit
_inp = sys.stdin.buffer.read().split(b'\n')[::-1]
input = lambda : _inp.pop().decode('ascii')
_out = __pypy__.builders.BytesBuilder()
class dummy:
    def flush(self):
        pass
    def write(self, s):
        _out.append(s.encode('ascii'))
sys.stdout = dummy()
atexit.register(lambda: os.write(1, _out.build()))
###
 
t = int(input())
for _ in range(t):
    n = int(input())
    A = [0]*n
    ind = 1
 
    buckets = [[] for _ in range(n + 2)]
    buckets[n].append(0)
    for le in reversed(range(1, n + 1)):
        b = buckets[le]
        b.sort()
        for l in b:
            mid = l + (le - 1 >> 1) 
            A[mid] = ind
            ind += 1
            if le > 1:
                buckets[mid - l].append(l)
                buckets[l + le - (mid + 1)].append(mid + 1)
    print(*A)