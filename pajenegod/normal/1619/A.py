t = int(input())
for _ in range(t):
    S = input()
    n = len(S)
    if S[:n//2] == S[n//2:]:
        print('YES')
    else:
        print('NO')