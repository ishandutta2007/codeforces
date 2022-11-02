from sys import stdout

n, k = map(int, input().split())
ans = n
kek = [0] * (k + 1)
real = 10 ** 9 + 1
reali = -1
for i in range(k + 1):
    print('?', end=' ')
    for j in range(k + 1):
        if i != j:
            print(j + 1, end=' ')
    print()
    stdout.flush()
    kek[i], a = map(int, input().split())
    if a < real:
        real = a
        reali = kek[i]
cnt = 0
for i in range(k + 1):
    if kek[i] == reali:
        cnt += 1
print('!', k + 1 - cnt)
stdout.flush()