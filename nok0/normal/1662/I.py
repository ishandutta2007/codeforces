import sys
input = sys.stdin.buffer.readline
read = sys.stdin.buffer.read

INF = 10 ** 18

N, M = map(int, input().split())
ps = list(map(int, input().split()))
xs = list(map(int, input().split()))

xs.sort()
xs.insert(0, -INF)
xs.append(INF)
M += 2

ice_idx = 0
dists = [0] * N
for i in range(N):
    hut = i * 100
    while xs[ice_idx + 1] < hut:
        ice_idx += 1
    dists[i] = min(abs(xs[ice_idx] - hut), abs(xs[ice_idx + 1] - hut))

events = []
for i, (p, d) in enumerate(zip(ps, dists)):
    if d == 0:
        continue
    hut = i * 100
    events.append((4 * (hut - d) + 1, p))
    events.append((4 * (hut + d) - 1, -p))
events.sort()
answer = 0
tmp = 0
for _, p in events:
    tmp += p
    answer = max(answer, tmp)

print(answer)