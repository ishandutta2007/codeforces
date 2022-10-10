t = int(input())
for i in range(t):
    n = int(input())
    a = sorted(list(set(map(int, input().split()))))
    b = True
    for j in range(len(a)):
        if j > 0 and a[j - 1] - a[j] != -1:
            b = False
    if b:
        print('YES')
    else:
        print('NO')