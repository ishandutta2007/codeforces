#!/usr/bin/env python2
import os
from io import BytesIO

import _numpypy.multiarray as np

range = xrange
input = BytesIO(os.read(0, os.fstat(0).st_size)).readline


def main():
    n, k = map(int, input().split())
    a = sorted(int(i) for i in input().split())

    next_end = [0] * n

    i, j = 0, 0
    while j < n:
        if a[i] + 5 >= a[j]:
            j += 1
        else:
            i += 1

        next_end[i] = j

    dp = np.zeros((n + 1, k + 1), dtype='int64')
    for i in range(n - 1, -1, -1):
        x = next_end[i]
        for j in range(1, k + 1):
            dp[i,j] = max(1 + dp[i+1,j - 1], dp[i+1,j], x - i + dp[x,j - 1])

    os.write(1, str(dp[0][k]))


if __name__ == '__main__':
    main()