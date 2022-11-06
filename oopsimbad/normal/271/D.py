s = [ord(x) - 97 for x in input()]
ok = [x == '1' for x in input()]

k = int(input())
n = len(s)

hashes = set()
MOD1 = 10**9 + 7
MOD2 = 998244353

for i in range(n):
    cnt = 0
    curhash1 = 0
    curhash2 = 0
    for j in range(i, n):
        if not ok[s[j]]:
            cnt += 1
        if cnt > k:
            break
        curhash1 = (curhash1 * 27 + s[j] + 1) % MOD1
        curhash2 = (curhash2 * 27 + s[j] + 1) % MOD2
        hashes.add((curhash1, curhash2))
print(len(hashes))