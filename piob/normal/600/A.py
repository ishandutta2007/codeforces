import re

s = raw_input()

s = re.split(",|;", s)

a = []
b = []

for w in s:
    try:
        if w[0] == '0' and len(w) > 1:
            w[0] = 'a'
        a += [str(int(w))]
    except:
        b += [w]

if len(a) == 0:
    print '-'
else:
    print '"' + ','.join(a) + '"'

if len(b) == 0:
    print '-'
else:
    print '"' + ','.join(b) + '"'