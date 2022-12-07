s = raw_input()

vows = "AOYEUI"

for v in vows:
    s = s.replace(v, '')
    s = s.replace(v.lower(), '')

s = s.lower().replace('', '.')

print s[:-1]