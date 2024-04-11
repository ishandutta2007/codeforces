k = int(input())
n = input()

digits = []

for c in n:
    digits.append(ord(c) - ord('0'))

digits.sort()
cur = sum(digits)
ans = 0

for d in digits:
    if cur < k:
        cur += 9 - d
        ans += 1

print(ans)