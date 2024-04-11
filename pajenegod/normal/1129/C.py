import os, sys
# Testing meooows code
nums = list(map(int, os.read(0, os.fstat(0).st_size).split()))

MOD = 10 ** 9 + 7
BAD = ([0, 0, 1, 1], [0, 1, 0, 1], [1, 1, 1, 0], [1, 1, 1, 1])

def zfunc(s):
    z = [0] * len(s)
    l = r = 0
    for i in range(1, len(s)):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < len(s) and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1
    return z

n = nums[0]
s = []
sm = 0
ans = []
for i in range(1, n + 1):
    s.append(nums[i])
    cur = 0
    f = [0] * (i + 1)
    f[i] = 1
    for j in range(i - 1, -1, -1):
        f[j] = f[j + 1]
        if j + 1 < i:
            f[j] = (f[j] + f[j + 2])%MOD
            
            if j + 2 < i:
                f[j] = (f[j] + f[j + 3])%MOD
                if j + 3 < i and s[j : j + 4] not in BAD:
                    f[j] = (f[j] + f[j + 4])%MOD
    z = zfunc(s[::-1])
    new = i - max(z)
    for x in f[:new]:
        sm = (sm + x)%MOD
    ans.append(sm)


os.write(1, b'\n'.join(str(x).encode() for x in ans))