N = int(raw_input())
cubes = dict()

for i in xrange(N):
    color, size = map(int, raw_input().split(' '))

    if color not in cubes:
        cubes[color] = []

    cubes[color].append((size, i))

bests = [[(-10**18, -1)] * (N + 5), [(-10**18, -1)] * (N + 5)]
bests[0][0] = bests[1][0] = (0, 0)

for color in cubes.iterkeys():
    cubes[color].sort(reverse = True)
    sizes = cubes[color]

    n = len(sizes)
    accum = 0

    for i in xrange(n):
        accum += sizes[i][0]

        if accum > bests[0][i + 1][0]:
            bests[1][i + 1], bests[0][i + 1] = bests[0][i + 1], (accum, color)
        elif accum > bests[1][i + 1][0]:
            bests[1][i + 1] = (accum, color)

best = (0, 0, 0, 0)
best_sum = -1

def check_best(list0, len0, list1, len1):
    global bests
    global best
    global best_sum

    pair0 = bests[list0][len0]
    pair1 = bests[list1][len1]

    if pair0[1] != pair1[1] and pair0[0] + pair1[0] > best_sum:
        best_sum = pair0[0] + pair1[0]
        best = (len0, list0, len1, list1)

for i in xrange(N + 1):
    check_best(0, i, 1, i)
    check_best(0, i, 0, i + 1)
    check_best(0, i, 1, i + 1)
    check_best(1, i, 0, i + 1)

answer = []

len0 = best[0]
list0 = best[1]
color0 = bests[list0][len0][1]
len1 = best[2]
list1 = best[3]
color1 = bests[list1][len1][1]
assert color0 != color1

ind0, ind1 = 0, 0
turn = 1

while ind0 < len0 or ind1 < len1:
    if turn == 0:
        answer.append(cubes[color0][ind0][1])
        ind0 += 1
        turn = 1
    else:
        answer.append(cubes[color1][ind1][1])
        ind1 += 1
        turn = 0

n = len(answer)
print best_sum
print n

for i in xrange(n):
    print answer[i] + 1,

print ''