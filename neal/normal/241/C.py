H = 100
W = 100000

L, R, N = map(int, raw_input().split())
scores = [0 for i in xrange(N)]
levels = [0 for i in xrange(N)]
bounds = [(0, 0) for i in xrange(N)]

for i in xrange(N):
    line = raw_input().split()
    scores[i] = int(line[0])
    levels[i] = 1 if line[1] == 'T' else 0
    bounds[i] = (float(line[2]), float(line[3]))

def get_points(level, x):
    total = 0
    mirror = -1
    
    for i in xrange(N):
        if levels[i] == level and bounds[i][0] <= x <= bounds[i][1]:
            total += scores[i]
            mirror = i
    
    return (total, mirror)

def solve():
    best = 0

    for bounces in xrange(1, N + 1):
        NR = H * bounces + (R if bounces % 2 == 0 else H - R)
        total = 0
        mirrors = set()

        for level in xrange(1, bounces + 1):
            x = float(level * H - L) / (NR - L) * W
            (points, mirror) = get_points(level % 2, x)
            total += points

            if mirror in mirrors or mirror == -1:
                total = -1000000000
            else:
                mirrors.add(mirror)

        best = max(best, total)

    return best

up = solve()

L = H - L
R = H - R

for i in xrange(N):
    levels[i] = 1 - levels[i]

down = solve()
print max(up, down)