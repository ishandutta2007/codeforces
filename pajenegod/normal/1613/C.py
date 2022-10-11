import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n,h = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]

    def check(k):
        dam = k
        for i in range(n - 1):
            dam += min(k, A[i + 1] - A[i])
        return dam >= h

    l = 1
    r = 10**18
    while l < r:
        mid = l + r >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1
    
    print(l)