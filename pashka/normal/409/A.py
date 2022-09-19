__author__ = 'Pavel Mavrin'

a = input().strip()
b = input().strip()

n = len(a) // 2

x = 0

figs = ["[]", "()", "8<"]

for i in range(n):
    s1 = figs.index(a[i * 2: (i + 1) * 2])
    s2 = figs.index(b[i * 2: (i + 1) * 2])
    if s2 == (s1 + 1) % 3:
        x += 1
    if s1 == (s2 + 1) % 3:
        x -= 1

if x > 0:
    print("TEAM 1 WINS")
elif x < 0:
    print("TEAM 2 WINS")
else:
    print("TIE")