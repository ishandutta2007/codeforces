def solve_case():
    global N, S, K
    N, S, K = map(int, input().split())
    A = set(map(int, input().split()))
    best = N
    low = max(S - K, 1)
    high = min(S + K, N)

    for floor in range(low, high + 1):
        if floor not in A:
            best = min(best, abs(S - floor))

    print(best)

tests = int(input())

for test in range(tests):
    solve_case()