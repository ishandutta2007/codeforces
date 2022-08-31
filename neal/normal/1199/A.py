N, X, Y = map(int, input().split())
A = list(map(int, input().split()))

for i in range(N):
    valid = True

    for j in range(i - X, i + Y + 1):
        if j < 0 or j >= N:
            continue

        if A[i] > A[j]:
            valid = False
            break

    if valid:
        print(i + 1)
        exit(0)