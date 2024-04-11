# not my code
# https://codeforces.com/contest/1355/submission/92200105
import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    
    n = int(input())
    a = list(map(int,input().split()))
    if n == 1 and a[0] == 1:
        out.append("1")
        continue
    elif n==1:
        out.append("0")
        continue
    a = sorted(a)
    count = 1
    total = 0
    for x in a:
        if x <= count:
            total+=1
            count = 1
        else:
            count+=1
    out.append(str(total))
print ("\n".join(out))