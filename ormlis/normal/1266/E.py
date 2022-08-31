from sys import stdin
n = int(stdin.readline())

arr = list(map(int, stdin.readline().split()))
d = [0] * n
ach = [dict() for i in range(n)]
ans = sum(arr)
q = int(stdin.readline())
a = stdin.readlines()
answers = []
for i in range(q):
    s, t, u = map(int, a[i].split())
    s -= 1
    u -= 1
    if ach[s].get(t, -1) != -1:
        d[ach[s][t]] -= 1
        if d[ach[s][t]] < arr[ach[s][t]]:
            ans += 1
    ach[s][t] = u
    if u != -1:
        d[u] += 1
        if d[u] <= arr[u]:
            ans -= 1
    answers.append(str(ans))
print('\n'.join(answers))