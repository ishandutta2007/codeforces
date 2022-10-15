s = raw_input()

k = {}

k['?'] = 0
for i in range(10):
    k[str(i)] = 0
    k[chr(65+i)] = 0

for m in s:
    k[m] += 1

p = 0
for i in range(10):
    if k[chr(65+i)] > 0:
        p += 1

t = 1
for i in range(0,p):
    t *= (10-i)

t *= 10**k['?']

if s[0] == '?':
    t /= 10
    t *= 9
elif s[0] >= 'A' and s[0] <= 'J':
    t /= 10
    t *= 9

print t