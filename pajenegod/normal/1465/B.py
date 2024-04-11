# not my code
# https://codeforces.com/contest/1465/submission/102364715
import sys
range = xrange
input = sys.stdin.readline
 
def check(n):
    for c in reversed(str(n)):
        if c > '1' and n % (ord(c) - 48) != 0:
            return False
    return True
 
for _ in range(int(input())):
    n = int(input())
    while not check(n):
        n += 1
    print(n)