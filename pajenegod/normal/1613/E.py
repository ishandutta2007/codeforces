import sys

inp = sys.stdin.read().split()
ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    m = int(inp[ii]); ii += 1

    root = -1

    mat = []
    for i in range(n):
        line = inp[ii]; ii += 1
        if 'L' in line:
            j = line.index('L')
            root = i * m + j
        mat += [+(c == '#') for c in line]

    def check(node):
        i,j = divmod(node, m)
        
        walls = 0
        nei = node - m
        walls += i == 0 or mat[nei] == 1
        
        nei = node + m
        walls += i + 1 == n or mat[nei] == 1
        
        nei = node - 1
        walls += j == 0 or mat[nei] == 1
        
        nei = node + 1
        walls += j + 1 == m or mat[nei] == 1
        
        return walls

    bfs = [root]
    mat[bfs[0]] = -1

    walls = [check(node) for node in range(n * m)]
    
    for node in bfs:
        i,j = divmod(node, m)
        
        nei = node - m
        if i and not mat[nei]:
            walls[nei] += 1
            if walls[nei] >= 3:
                mat[nei] = -1
                bfs.append(nei)
        
        nei = node + m
        if i + 1 < n and not mat[nei]:
            walls[nei] += 1
            if walls[nei] >= 3:
                mat[nei] = -1
                bfs.append(nei)
        
        nei = node - 1
        if j and not mat[nei]:
            walls[nei] += 1
            if walls[nei] >= 3:
                mat[nei] = -1
                bfs.append(nei)
        
        nei = node + 1
        if j + 1 < m and not mat[nei]:
            walls[nei] += 1
            if walls[nei] >= 3:
                mat[nei] = -1
                bfs.append(nei)
    
    mat[bfs[0]] = 2
    
    mapper = '.#L+'

    for i in range(n):
        line = mat[i*m: (i + 1)*m]
        print(''.join(mapper[c] for c in line))