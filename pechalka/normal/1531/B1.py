n = int(input())
A = dict()
B = dict()
for i in range(n):
    w, h = map(int, input().split())
    if w > h:
        w += h
        h = w - h
        w = w - h
    if w not in A:
        A[w] = 0
    if h not in A:
        A[h] = 0
    A[w] += 1
    A[h] += 1
    if (w, h) not in B:
        B[(w, h)] = 0
    B[(w, h)] += 1
    if w == h:
        A[w] -= 1
        B[(w, h)] -= 1
ans = 0
for x in A.values():
    ans += x * (x - 1) // 2
for x in B.values():
    ans -= x * (x - 1) // 2

print(ans)