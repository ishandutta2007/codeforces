n = int(input())
arr = list(map(int, input().split()))
d = {}
for i in arr:
    d[i] = d.get(i, 0) + 1
d2 = {}
for k, v in d.items():
    d2.setdefault(v, []).append(k)

s = n
prev = 0
ansp = ansq = anss = 0
for p in range(n, 0, -1):
    q = s // p
    if p <= q and q * p > anss:
        anss = q * p
        ansq = q
        ansp = p
    prev += len(d2.get(p, []))
    s -= prev


def get_ans():
    cur_i = 0
    cur_j = 0
    cur = 0
    for k, v in d3:
        for val in v:
            f = min(k, anss - cur, ansp)
            cur += f
            for i in range(f):
                cur_i = (cur_i + 1) % ansp
                cur_j = (cur_j + 1) % ansq
                if ans[cur_i][cur_j]:
                    cur_i = (cur_i + 1) % ansp
                ans[cur_i][cur_j] = val

print(anss)
print(ansp, ansq)
d3 = sorted(d2.items(), reverse=True)
ans = [[0] * ansq for i in range(ansp)]
get_ans()
for i in range(ansp):
    print(*ans[i])