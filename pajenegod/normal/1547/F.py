import sys
input = sys.stdin.readline

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

class RangeQuery:
    def __init__(self, data, func=min):
        self.func = func
        self._data = _data = [list(data)]
        i, n = 1, len(_data[0])
        while 2 * i <= n:
            prev = _data[-1]
            _data.append([func(prev[j], prev[j + i]) for j in range(n - 2 * i + 1)])
            i <<= 1

    def query(self, start, stop):
        """func of data[start, stop)"""
        depth = (stop - start).bit_length() - 1
        return self.func(self._data[depth][start], self._data[depth][stop - (1 << depth)])


t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    RQ = RangeQuery(2 * A, gcd)
    base = RQ.query(0,n)

    inter = 0
    for i in range(n):
        for bit in range(n.bit_length() + 1)[::-1]:
            r = i + inter + (1 << bit)
            if r < 2*n and RQ.query(i, r) > base:
                inter = r - i
    
    print inter