import io, os
input = io.StringIO(os.read(0, os.fstat(0).st_size).decode()).readline

ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())

n = ii()
a = [li() for _ in range(4 * n + 1)]
lox = min(p[0] for p in a)
hix = max(p[0] for p in a)
loy = min(p[1] for p in a)
hiy = max(p[1] for p in a)
loxs = [i for i in range(len(a)) if a[i][0] == lox]
hixs = [i for i in range(len(a)) if a[i][0] == hix]
loys = [i for i in range(len(a)) if a[i][1] == loy]
hiys = [i for i in range(len(a)) if a[i][1] == hiy]
singles = [s for s in (loxs, hixs, loys, hiys) if len(s) == 1]
if not singles:
    alls = set(loxs + hixs + loys + hiys)
    ans = [i for i in range(len(a)) if i not in alls][0]
else:
    ans = singles[0][0]
print(*a[ans])