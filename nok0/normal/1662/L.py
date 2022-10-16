import sys
import bisect

input = sys.stdin.buffer.readline
read = sys.stdin.buffer.read

N, V = map(int, input().split())
Ts = list(map(int, input().split()))
As = list(map(int, input().split()))

points = []
for T, A in zip(Ts, As):
    B = T * V
    x = B - A
    y = B + A
    if x < 0 or y < 0:
        continue
    points.append((x, y))

points.sort()
# print(points)

lis = []
for _, w in points:
    index = bisect.bisect_right(lis, w)
    if index < len(lis):
        lis[index] = w
    else:
        lis.append(w)

print(len(lis))