n = int(input())
ans = 0
while n:
    maxd = 0
    tmp = n
    while tmp:
        maxd = max(maxd, tmp % 10)
        tmp //= 10
        
    n -= maxd
    ans += 1
    
print(ans)