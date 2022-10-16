n, k = map(int, input().split())
M = 998244353
 
ft = [1]*500001
for i in range(1, 500001):
    ft[i] = (ft[i-1]*i) % M
 
ans = 0
for i in range(1, n+1):
    a = (n//i) - 1
    if (a < k-1): break
    ans = (ans + (ft[a])*pow(ft[k-1]*ft[a-k+1], M-2, M)) % M
print(ans)