n = input().strip()

cnt = [n.count(chr(ord('0') + i)) for i in range(10)]

def fac(n):
    if n <= 1: return 1
    return n * fac(n-1)

def C(x):
    ans = fac(sum(x))
    for v in x:
        ans //= fac(v)
    return ans

def calc(x, c):
    if x == []: return C(c)
    if x[0] == 0: return calc(x[1:], c)
    ans = 0
    if x[0] < 0:
        for i in range(0, -x[0]+1):
            ans += calc(x[1:], c + [i])
    else:
        for i in range(1, x[0]+1):
            ans += calc(x[1:], c + [i])
    return ans

ans = 0
for i in range(1, 10):
    if cnt[i] > 0:
        cnt[i] -= 1
        cnt[i] = -cnt[i]
        ans += calc(cnt, [])
        cnt[i] = -cnt[i]
        cnt[i] += 1

print (ans)