t, s, q = map(int, input().split())
c = s
ans = 1
while s < t:
    s += q - 1
    c -= 1
    if c == 0 and s < t:
       ans += 1
       c = s
print(ans)