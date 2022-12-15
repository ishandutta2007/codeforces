import re

s = raw_input()

def parse(s):
    lis = s.split('.')
    res = 0
    cur = 1
    flag = True
    for i in lis[::-1]:
        if len(i) == 2 and flag:
            res += int(i) / 100.0
        else:
            res += int(i) * cur
            cur *= 1000
        flag = False
    return res

lis = re.findall(r'[0-9\.]+', s)

ans = sum(parse(i) for i in lis)

s = ''

x = ans - int(ans)
x = int(round(x * 100))
s = str(x / 10) + str(x % 10)

ans = int(ans)

if ans == 0:
    s = '0.' + s

while ans:
    x = ans % 1000
    ans /= 1000
    if ans == 0:
        s = str(x) + '.' +  s
    else:
        s = str(x / 100) + str((x / 10) % 10) + str(x % 10) + '.' + s

if s.endswith('.00'):
    s = s[:-3]

print s