import sys

inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n,m,k = inp[ii: ii + 3]; ii += 3

    X = inp[ii: ii + n]; ii += n

    heights = [[] for _ in range(n)]
    heights[0].append(0)
    heights[n - 1].append(m - 1)

    iii = ii
    for _ in range(k):
        a,b,c,d,h = inp[ii: ii + 5]; ii += 5

        a -= 1
        b -= 1
        c -= 1
        d -= 1

        heights[a].append(b)
        heights[c].append(d)
    ii = iii
    
    heights = [sorted(set(height)) for height in heights]
    mappers = [{} for _ in range(n)]
    for i in range(n):
        height = heights[i]
        for j in range(len(height)):
            mappers[i][height[j]] = j

    jumps = [[[] for _ in range(len(height))] for height in heights]
    for _ in range(k):
        a,b,c,d,h = inp[ii: ii + 5]; ii += 5

        a -= 1
        b -= 1
        c -= 1
        d -= 1

        b = mappers[a][b]
        d = mappers[c][d]

        jumps[a][b].append((c,d,h))

    
    inf = 10**18

    DP = [[inf] * len(height) for height in heights]
    DP[0][0] = 0
    
    for i in range(n):
        x = X[i]
        dp = DP[i]
        jump = jumps[i]
        height = heights[i]
        mm = len(height)

        if not mm:
            continue

        val = dp[0]
        for j in range(1,mm):
            val = dp[j] = min(val + x * (height[j] - height[j - 1]), dp[j])
        
        val = dp[-1]
        for j in range(mm - 1)[::-1]:
            val = dp[j] = min(val + x * (height[j + 1] - height[j]), dp[j])

        for j in range(mm):
            for c,d,h in jump[j]:
                DP[c][d] = min(DP[c][d], dp[j] - h)

    
    out = DP[-1][-1]
    if out >= 10**17:
        print('NO ESCAPE')
    else:
        print(out)