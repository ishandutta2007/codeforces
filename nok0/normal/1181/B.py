n = int(input())
s = input()
res = int(s)

for i in range(-1, 2):
    mid = n // 2 + i
    while mid > 0 and mid < n and s[mid] == "0":
        mid += -1 if i < 0 else 1
    if mid > 0 and mid < n:
        res = min(res, int(s[:mid]) + int(s[mid:]))

print(res)