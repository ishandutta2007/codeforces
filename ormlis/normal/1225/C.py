n, p = map(int, input().split())

ans = -1
i = 1
while True:
    n -= p
    if n < i:
        print(ans)
        break
    k = str(bin(n)[2:]).count('1')
    if i >= k:
        print(i)
        break
    i += 1