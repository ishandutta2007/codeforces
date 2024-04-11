#!/usr/bin/env python2
"""
This file is part of https://github.com/cheran-senthil/PyRival
Copyright 2019 Cheran Senthilkumar <hello@cheran.io>

"""
from __future__ import division, print_function

import itertools
import os
import sys
from atexit import register
from io import BytesIO

range = xrange

filter = itertools.ifilter
map = itertools.imap
zip = itertools.izip

sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))

input = lambda: sys.stdin.readline().rstrip('\r\n')

res = 0


def main():
    n = int(input())
    a = input().split()

    red_cnt = a.count('1')
    blue_cnt = a.count('2')

    tree = [[] for _ in range(n)]
    for _ in range(n - 1):
        v, u = map(int, input().split())
        tree[v - 1].append(u - 1)
        tree[u - 1].append(v - 1)

    dp, visited, P = [[0, 0] for _ in range(n)], [False]*n, [-1]*n

    def dfs(root):
        res = 0
        
        stack = [(root,-1)]
        while stack:
            node,parent = stack.pop()
            if not visited[node]:
                visited[node] = True
                P[node] = parent
                stack.append((node,parent))
                for child in tree[node]:
                    if not visited[child]:
                        stack.append((child,node))
            elif P[node]==parent:
                node_cnt = dp[node]
                node_cnt[0] += a[node] == '1'
                node_cnt[1] += a[node] == '2'
                for child in tree[node]:
                    if child != P[node]:
                        child_cnt = dp[child]
                        node_cnt[0] += child_cnt[0]
                        node_cnt[1] += child_cnt[1]
                        if ((child_cnt[0] == red_cnt) and (child_cnt[1] == 0)) or ((child_cnt[0] == 0) and
                                                                                   (child_cnt[1] == blue_cnt)):
                            res += 1
        return res
    print(dfs(0))

if __name__ == '__main__':
    main()