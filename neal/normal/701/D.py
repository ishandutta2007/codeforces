N, L, V1, V2, K = map(int, raw_input().split())
N = (N + K - 1) // K
L = 1.0 * L / V1
V2 = 1.0 * V2 / V1
D = L / (2 * (N - 1) / (V2 + 1) + 1)
print L - (1 - 1 / V2) * D