N = int(input())
H = [int(_) for _ in input().split()]

suffix_max = [0] * (N + 1)

for i in range(N - 1, -1, -1):
    suffix_max[i] = max(H[i], suffix_max[i + 1])

ans = [0] * N

for i in range(N):
    ans[i] = max(suffix_max[i + 1] - H[i] + 1, 0)

print(' '.join(str(_) for _ in ans))