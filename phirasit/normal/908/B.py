import itertools

n, m = map(int, input().split())
data = [input().strip() for i in range(n)]
move = list(map(int, list(input().strip())))

def valid(data, moves):

    x, y = 0, 0
    for i, row in enumerate(data):
        for j, ch in enumerate(row):
            if ch == 'S':
                x, y = i, j
    
    for m in moves:
        if m == 'N': x -= 1
        if m == 'E': y -= 1
        if m == 'W': y += 1
        if m == 'S': x += 1

        if not(0 <= x < len(data) and 0 <= y < len(data[0])):
            return False
        
        if data[x][y] == '#':
            return False
        
        if data[x][y] == 'E':
            return True

    return False

ans = 0
for x in itertools.permutations(range(4)):

    direction = {a:b for a, b in zip(x, list("NEWS"))}
    moves = list(map(lambda x: direction[x], move))
    if valid(data, moves):
        ans += 1

print (ans)