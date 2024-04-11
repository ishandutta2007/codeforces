# Not my code: https://codeforces.com/contest/1248/submission/155879655
 
import sys
from array import array
 
def counter(A, a):
    count = 0
    for b in A:
        count += a == b
    return count
 
def cal(l, r):
    cum = [0]*(n+1)
    ret = 0
    a[l], a[r] = a[r], a[l]
 
    for i in range(n):
        cum[i + 1] = cum[i] + a[i]
 
    cum.pop(0)
    
    mi = min(cum)
    a[l], a[r] = a[r], a[l]
    return counter(cum, mi)
 
 
input = lambda: sys.stdin.buffer.readline().decode().strip()
n, a = int(input()), [1 if x == '(' else -1 for x in input()]
 
if sum(a) != 0:
    exit(print(f'0\n1 1'))
 
ans = cal(0, 0)
l, r = 1, 1
 
for i in range(n - 1):
    for j in range(i + 1, n):
        if a[i] != a[j]:
            tem = cal(i, j)
            if tem > ans:
                ans, l, r = tem, i + 1, j + 1
 
print(f'{ans}\n{l} {r}')