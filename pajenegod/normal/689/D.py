import sys
range = xrange
input = raw_input

class RangeQuery:
    def __init__(self, data, func=min):
        self.func = func
        self._data = _data = [list(data)]
        i, n = 1, len(_data[0])
        while 2 * i <= n:
            prev = _data[-1]
            _data.append([func(prev[j], prev[j + i]) for j in range(n - 2 * i + 1)])
            i <<= 1

    def query(self, begin, end):
        depth = (end - begin).bit_length() - 1
        return self.func(self._data[depth][begin], self._data[depth][end - (1 << depth)])

n = int(input())
A = RangeQuery((int(x) for x in input().split()), max)
B = RangeQuery((int(x) for x in input().split()), min)

count = 0
for i in range(n):
    a = i
    b = n
    while a < b:
        c = a + b + 1 >> 1
        val = A.query(i, c) - B.query(i, c)
        if val < 0:
            a = c
        else:
            b = c - 1
    
    L = a

    a = i
    b = n
    while a < b:
        c = a + b + 1 >> 1
        val = A.query(i, c) - B.query(i, c)
        if val <= 0:
            a = c
        else:
            b = c - 1
    
    R = a
    count += R - L

print count