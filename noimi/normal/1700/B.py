T = int(input())

for _ in range(T):
    n = int(input())
    N = input()
    if N[0] == '9':
        print((10 ** (n + 1) - 1) // 9 - int(N))
    else:
        print((10 ** n) - 1 - int(N))