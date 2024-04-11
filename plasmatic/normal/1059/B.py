import sys
import copy
lines = iter(sys.stdin)

def nexts():
    return next(lines)

def nextint():
    return int(nexts())

def snexts():
    return next(lines).split(' ')

def snextint():
    return map(int, snexts())

def array(length, base=0):
    return [base] * length

def matrix(length, width, base=0):
    return [[base] * width for _ in range(length)]

n, m = snextint()
grid = array(n, [])

for i in range(n):
    grid[i] = list(nexts())

grid2 = copy.deepcopy(grid)

for i in range(1, n - 1):
    for j in range(1, m - 1):
        # print('Attempting on i=%d,j=%d'%(i,j))
        if grid[i - 1][j] == '#' and grid[i - 1][j + 1] == '#' and grid[i][j + 1] == '#' and grid[i + 1][j + 1] == '#' and grid[i + 1][j] == '#' and grid[i + 1][j - 1] == '#' and grid[i][j - 1] == '#' and grid[i - 1][j - 1] == '#':
            grid2[i - 1][j] = '.'
            grid2[i - 1][j + 1] = '.'
            grid2[i][j + 1] = '.'
            grid2[i + 1][j + 1] = '.'
            grid2[i + 1][j] = '.'
            grid2[i + 1][j - 1] = '.'
            grid2[i][j - 1] = '.'
            grid2[i - 1][j - 1] = '.'

match = True
for i in grid2:
    for ch in i:
        if ch == '#':
            match = False
            break

if match:
    print('YES')
else:
    print('NO')