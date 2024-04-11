# Not my code https://codeforces.com/contest/1623/submission/140947850

''' A. Robot Cleaner
https://codeforces.com/contest/1623/problem/A
'''
 
import io, os, sys
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline  # decode().strip() if str
output = sys.stdout.write
 
 
# TLE pypy3-64: https://codeforces.com/contest/1623/submission/140947500
# AC pypy3: https://codeforces.com/contest/1623/submission/140947572
# AC python3.8: https://codeforces.com/contest/1623/submission/140947654
def solve(R, C, r1, c1, r2, c2):
    if r1 == r2 or c1 == c2: return 0
 
    res = 0
    dr = dc = 1
    while True:
        if not 1 <= r1+dr <= R: dr = -dr
        if not 1 <= c1+dc <= C: dc = -dc
        res += 1
        r1 += dr
        c1 += dc
        if r1 == r2 or c1 == c2: break
    return res
 
'''
# AC pypy3-64: https://codeforces.com/contest/1623/submission/140947749
 
def solve(R, C, r1, c1, r2, c2):
    if r1 == r2 or c1 == c2: return 0
 
    res = 0
    dr = dc = 1
    while True:
        if r1 == r2 or c1 == c2: break
        if not 1 <= r1+dr <= R: dr = -dr
        if not 1 <= c1+dc <= C: dc = -dc
        res += 1
        r1 += dr
        c1 += dc
    return res
'''
 
def main():
    T = int(input())
    for _ in range(T):
        R, C, r1, c1, r2, c2 = list(map(int, input().split()))
        out = solve(R, C, r1, c1, r2, c2)
        output(f'{out}\n')
 
 
if __name__ == '__main__':
    main()