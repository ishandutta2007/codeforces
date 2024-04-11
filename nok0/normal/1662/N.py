import sys
import random

input = sys.stdin.buffer.readline
read = sys.stdin.buffer.read

N = int(input())
As = [list(map(int, input().split())) for _ in range(N)]

# N = 1500
# As = list(range(1, N ** 2 + 1))
# random.shuffle(As)
# As = [As[i * N:(i + 1) * N] for i in range(N)]

ijs = [0] * (N ** 2)
for i in range(N):
    for j in range(N):
        ijs[As[i][j] - 1] = (i, j)

answer = 0
row_sum = [0] * N
col_sum = [0] * N
for i, j in ijs:
    l_row = row_sum[i]
    g_row = N - 1 - row_sum[i]
    l_col = col_sum[j]
    g_col = N - 1 - col_sum[j]
    answer += l_col * g_row + g_col * l_row
    row_sum[i] += 1
    col_sum[j] += 1

assert answer % 2 == 0
print(answer // 2)