N, M = map(int, raw_input().split(' '))
#grades = [[0] * M] * N
grades = [[0] * M for i in range(N)]
successful = [False] * N

for i in range(N):
    line = raw_input()
    assert M == len(line)
    
    for j in range(M):
        grades[i][j] = ord(line[j])

for j in range(M):
    high = 0

    for i in range(N):
        high = max(high, grades[i][j])

    for i in range(N):
        if grades[i][j] == high:
            successful[i] = True

print sum(successful)