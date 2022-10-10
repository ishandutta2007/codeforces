n = int(input())
sides = dict()
rectangles = dict()
for i in range(n):
    w, h = map(int, input().split())
    if sides.get(w) is None:
        sides[w] = 0
    if sides.get(h) is None:
        sides[h] = 0
    sides[w] += 1
    if w != h:
        sides[h] += 1
        rect = str(min(h, w)) + ' ' + str(max(h, w))
        if rectangles.get(rect) is None:
            rectangles[rect] = 0
        rectangles[rect] += 1
ans = 0
for s in sides.values():
    ans += s * (s - 1)
for r in rectangles.values():
    ans -= r * (r - 1)
print(ans // 2)