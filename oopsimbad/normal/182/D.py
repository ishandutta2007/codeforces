import math
s = input()
t = input()

gcd = math.gcd(len(s), len(t))

def test(k):
    for i in range(k):
        if s[i] != t[i]:
            return False

    for i in range(len(s)):
        if s[i] != s[i % k]:
            return False

    for i in range(len(t)):
        if t[i] != t[i % k]:
            return False
    return True

i = 1
ans = 0
while i*i < gcd:
    if gcd % i == 0:
        if test(i):
            ans += 1
        if test(gcd//i):
            ans += 1
    i += 1

if i*i == gcd and test(i):
    ans += 1

print(ans)