q = int(input())

for i in range(q):
    s = input()
    t = input()
    if set(s) & set(t):
        print('YES')
    else:
        print('NO')