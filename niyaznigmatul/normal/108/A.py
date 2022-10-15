def isPalindrom(s):
    return s == s[::-1]

h, m = map(int, raw_input().split(":"))
t = h * 60 + m
while True:
    t += 1
    if t == 1440:
        t = 0
    s = "%02d:%02d"%(t // 60, t % 60)
    if isPalindrom(s):
        print s
        break