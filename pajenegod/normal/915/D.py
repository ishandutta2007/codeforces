import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

forw = [[] for _ in range(n)]
back = [[] for _ in range(n)]
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    forw[u].append(v)
    back[v].append(u)

outdeg = [len(f) for f in forw]
indeg = [len(f) for f in back]
found = [0]*n

def update(outdeg, indeg, found):
    rems = []
    for node in range(n):
        if not found[node] and (not outdeg[node] or not indeg[node]):
            found[node] = 1
            rems.append(node)

    for node in rems:
        for nei in forw[node]:
            indeg[nei] -= 1
            if not indeg[nei] and not found[nei]:
                found[nei] = 1
                rems.append(nei)

        for nei in back[node]:
            outdeg[nei] -= 1
            if not outdeg[nei] and not found[nei]:
                found[nei] = 1
                rems.append(nei)
    return all(found)

ans = update(outdeg, indeg, found)
if ans:
    print 'YES'
    sys.exit()

checked = list(found)
for node in range(n):
    if checked[node] or indeg[node] != 1:
        continue
    for nei in back[node]:
        if not checked[nei] and outdeg[nei] == 1:
            indeg[node] -= 1
            outdeg[nei] -= 1
            checked[node] = 1
            checked[nei] = 1

            if update(list(outdeg), list(indeg), list(found)):
                print 'YES'
                sys.exit()
            indeg[node] += 1
            outdeg[nei] += 1
print 'NO'