#!/usr/bin/env python3
import os
import sys
from io import BytesIO, IOBase

class FastO:
    def __init__(self, fd=1):
        stream = BytesIO()
        self.flush = lambda: os.write(fd, stream.getvalue()) and not stream.truncate(0) and stream.seek(0)
        self.write = lambda b: stream.write(b.encode())


class ostream:
    def __lshift__(self, a):
        sys.stdout.write(str(a))
        return self


sys.stdout, cout = FastO(), ostream()

numbers, num, sign = [], 0, 1
for char in os.read(0, os.fstat(0).st_size):
    if char >= 48:
        num = num * 10 + char - 48
    elif char == 45:
        sign = -1
    elif char != 13:
        numbers.append(sign*num)
        num, sign = 0, 1

if char >= 48:
    numbers.append(sign*num)

getnum = numbers[::-1].pop


def main():
    n, m = getnum(), getnum()

    _dp = [[] for _ in range(n)]
    for i in range(n):
        ni = getnum()
        ai = [getnum() for _ in range(ni)]

        cumsum = [0] * (ni + 1)
        for j in range(ni):
            cumsum[j + 1] = cumsum[j] + ai[j]

        _dpi = [0] * (ni + 1)
        for j in range(ni + 1):
            for k in range(j, ni + 1):
                _dpi[ni + j - k] = max(_dpi[ni + j - k], cumsum[j] + cumsum[-1] - cumsum[k])
        _dp[i] = _dpi

    dp = [0] * (m + 1)
    for i in range(n):
        _dpi = _dp[i]
        for j in reversed(range(m + 1)):
            dpj = dp[j]
            for k in range(min(len(_dp[i]), j + 1)):
                dpj = max(dpj, _dpi[k] + dp[j - k])
            dp[j] = dpj

    cout << dp[m]


if __name__ == '__main__':
    main()