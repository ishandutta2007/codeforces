import sys
t = int(input())
for _ in range(t):
    n = int(input())

    S = [c if c != 'B' else 'G' for c in input()]
    S2 = [c if c != 'B' else 'G' for c in input()]

    print('YES' if S == S2 else 'NO')