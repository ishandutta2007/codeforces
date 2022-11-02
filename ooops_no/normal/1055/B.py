n, m, g = list(map(int, input().split()))
l = [0] + list(map(int, input().split())) + [0]
ans = 0
bit = [0] + [0] * n + [0]
output =[]
for i in range(1,n + 1):
    if l[i] > g:
        bit[i] = 1
        if bit[i - 1] == 0 and bit[i + 1] == 0:
            ans += 1
        elif bit[i - 1] == 1 and bit[i + 1] == 1:
            ans -= 1
for i in range(m):
    a = list(map(int, input().split()))
    if a[0] == 0:
        output.append(ans)
        continue
    else: l[a[1]] += a[2]
    if l[a[1]] > g:
        if bit[a[1]] == 0:
            bit[a[1]] = 1
            if bit[a[1] - 1] == 0 and bit[a[1] + 1] == 0:
                ans += 1
            elif bit[a[1] - 1] == 1 and bit[a[1] + 1] == 1:
                ans -= 1
print('\n'.join(map(str, output)))