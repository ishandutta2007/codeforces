n = int(input())
a = list(map(str, input().split()))
for i in range(n):
    q = set()
    for j in range(len(a[i])):
        q.add(a[i][j])
    q = list(q)
    q.sort()
    a[i] = q
s = set()
for i in range(n):
    s.add("".join(a[i]))
print(len(s))