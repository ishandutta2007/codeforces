n = input()
count = len(n)
n = (10 - len(n)) * "0" + n
min1 = 10
for i in range(1, 2 ** 10):
    b = bin(i)
    b = b[2:]
    b = (10 - len(b)) * "0" + b
    s = ""
    for i in range(10):
        if (b[i] == '1'):
            s += n[i]
    if (len(s) > 0 and s[0] == '0'):
        continue
    s = int(s)
    if (int(s ** 0.5) ** 2 == s):
        min1 = min(b[len(b) - count:].count("0"), min1)
if (min1 == 10):
    print(-1)
else:
    print(min1)