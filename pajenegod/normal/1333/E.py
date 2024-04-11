import sys
range = xrange
input = raw_input

n = int(input())
if n <= 2:
    print -1
    sys.exit()

B = [[6,7,9],[8,4,5],[1,3,2]]
def solve():
    A = [[0]*n for _ in range(n)]
    for i in range(3):
        for j in range(3):
            A[i][j] = B[i][j] + n * n - 9

    val = n * n - 9

    x = 0
    y = 3
    dx = -1
    dy = 0
    while val:
        A[y][x] = val
        val -= 1 
        if not val:
            break
        dx,dy = -dy,dx
        while not 0 <= y + dy < n or not 0 <= x + dx < n or A[y + dy][x + dx]:
            dx,dy = dy,-dx
        y += dy
        x += dx
    return A
A = solve()


print '\n'.join(' '.join(str(x) for x in a) for a in A)