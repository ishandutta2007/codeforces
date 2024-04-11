#!/usr/bin/env python3
from itertools import accumulate, groupby
from functools import reduce

def prod(a):
    return reduce(lambda x,y: min(x*y,10**6),a,1)

def solve_positive(a):
    if a == '': return '+'

    b = [''.join(v) for _,v in groupby(a, key=lambda x: x == '1')]

    if b[0][0] == '1':
        return '+' * len(b[0]) + solve_positive(a[len(b[0]):])
    
    if b[-1][0] == '1':
        return solve_positive(a[:-len(b[-1])]) + '+' * len(b[-1])
    
    p = [prod(map(int,x)) for x in b[::2]]
    q = [len(x) for x in b[1::2]]
    k = len(p)
    
    if prod(p) >= 10**6:
        return '+' + '*' * (len(a)-1) + '+'
    

    dp = [0] * k
    go = [k] * k
    for i in range(k)[::-1]:
        dp[i] = prod(p[i:])
        for j in range(i+1,k):
            ndp = prod(p[i:j]) + q[j-1] + dp[j]
            if ndp > dp[i]:
                dp[i], go[i] = ndp, j

    offset = [0] + list(accumulate(map(len,b)))

    res = ['*'] * (len(a)-1)
    i = go[0]
    while i < k:
        a = offset[2*i-1]-1
        b = offset[2*i]
        res[a:b] = '+' * (b-a)
        i = go[i]

    return '+' + ''.join(res) + '+'


def solve(a,ops):
    n = len(a)
    if len(ops) == 1: return ops * (n-1)
    if sorted(ops) == list('+-'): return '+' * (n-1)

    if sorted(ops) == list('*-'):
        k = a.index('0') if '0' in a else n
        if k == 0 or k == n: return '*' * (n-1)
        return '*' * (k-1) + '-' + '*' * (n-k-1)
    
    return ''.join(map(solve_positive,a.split('0')))[1:-1]

n = int(input())
a = ''.join(input().split())
ops = input()
b = solve(a,ops) + '\n'
for i in range(n):
    print(a[i], end='')
    print(b[i], end='')