import io, os
input = io.StringIO(os.read(0, os.fstat(0).st_size).decode()).readline

ii = lambda: int(input())
mi = lambda: map(int, input().split())
li = lambda: list(mi())

s, b = mi()
a = li()
z = [[-1, 0]] + sorted(li() for _ in range(b))
for i in range(1, b + 1):
    z[i][1] += z[i - 1][1]
v = [p[0] for p in z]
from bisect import bisect_right as ub
ans = [z[ub(v, x) - 1][1] for x in a]
print(*ans)