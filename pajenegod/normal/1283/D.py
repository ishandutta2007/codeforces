import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

X = inp[ii: ii + n]; ii += n

marked = set()
for x in X:
    marked.add(x)
marked.add(-2*10**9 - 1)
marked.add( 2*10**9 + 1)

pos = []
for x in X:
    if x + 1 not in marked:
        pos.append(x + 1)
        marked.add(x + 1)
    if x - 1 not in marked:
        pos.append(x - 1)
        marked.add(x - 1)
pick = []
tmp = []
cost = 1
total = 0
while m:
    pos.reverse()
    while m and pos:
        m -= 1
        total += cost
        x = pos.pop()
        pick.append(x)

        if x + 1 not in marked:
            tmp.append(x + 1)
            marked.add(x + 1)
        if x - 1 not in marked:
            tmp.append(x - 1)
            marked.add(x - 1)
    tmp,pos = pos,tmp
    cost += 1

print total
print ' '.join(str(x) for x in pick)