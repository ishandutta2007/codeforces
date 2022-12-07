a = raw_input()

u = 0
l = 0

for x in a:
    if x.isupper():
        u = u + 1
    else:
        l = l + 1

if u > l:
    print a.upper()
else:
    print a.lower()