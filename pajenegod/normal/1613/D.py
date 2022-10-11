import sys
input = sys.stdin.readline

MOD = 998244353 

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    
    ans = 0

    B = [0] * (n + 10)
    C = [0] * (n + 10)
    B[-1] = 1
    for a in A:
        base = B[a - 1] + B[a]

        B[a] = (B[a] + base) % MOD
        extra = B[a - 2] + C[a]
        
        extra2 = C[a + 2]

        ans += base + extra + extra2

        C[a] = (C[a] + extra) % MOD
            
        C[a + 2] = (C[a + 2] + extra2) % MOD

    print(ans % MOD)