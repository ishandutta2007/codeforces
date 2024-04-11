import sys, __pypy__, os, atexit

inp = sys.stdin.buffer.read().split(b'\n')[::-1]
input = lambda : inp.pop().decode('ascii')
_out = __pypy__.builders.BytesBuilder()
class dummy:
    def flush(self):
        pass
    def write(self, s):
        _out.append(s.encode('ascii'))
sys.stdout = dummy()
atexit.register(lambda: os.write(1, _out.build()))

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    
    count = [0]*n
    for k in range(n):
        count[(A[k] + k) % n] += 1
    if not all(count):
        print('NO')
    else:
        print('YES')