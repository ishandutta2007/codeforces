import sys
range = xrange
input = raw_input

m,n,k = [int(x) for x in input().split()]

total = 4 * n * m - 2 * n - 2 * m
if k > total:
    print 'NO'
    sys.exit()
print 'YES'


out = []
def move(S, count):
    if count == 0:
        return
    else:
        out.append((count, S))
    
x = 0
y = 0

w = n
h = m

while True:
    up = x&1
    if x == w - 1:
        if up:
            move('U', (h - 1))
            y -= h - 1
        else:
            move('D', (h - 1))
            y += h - 1
        break
    else:
        if up:
            move('RLU', (h - 1))
            y -= h - 1
        else:
            move('RLD', (h - 1))
            y += h - 1
        move('R',1)
        x += 1
while True:
    up = x & 1 == 0
    if up:
        move('U', (h - 1))
        y -= h - 1
    else:
        move('D', (h - 1))
        y += h - 1

    if x == 0:
        break

    move('L', 1)
    x -= 1

ans = []
for count, S in out:
    if count * len(S) <= k:
        k -= count * len(S)
        ans.append('%d %s' % (count, S))
    else:
        whole, extra = divmod(k, len(S))
        if whole:
            ans.append('%d %s' % (whole, S))
        if extra:
            ans.append('%d %s' % (1, S[:extra]))
        k = 0
    if k == 0:
        break
print len(ans)
print '\n'.join(ans)