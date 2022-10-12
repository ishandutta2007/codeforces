dir = {
    'N': (0, 1),
    'E': (1, 0),
    'W': (-1, 0),
    'S': (0, -1),
}

for tc in range(int(input())):
    cur, ans, vis = (0, 0), 0, set()
    for c in input():
        nxt = (cur[0] + dir[c][0], cur[1] + dir[c][1])

        if (cur, nxt) in vis:
            ans += 1
        else:
            ans += 5
            vis.add((cur, nxt))
            vis.add((nxt, cur))
        cur = nxt

    print(ans)