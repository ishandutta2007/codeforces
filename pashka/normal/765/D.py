n = int(input())
f = [int(x) - 1 for x in input().split()]
p = [-1] * n
g = [0] * n
h = [0] * n
m = 0
for i in range(n):
    if f[i] == i:
        p[i] = m
        h[m] = i + 1
        m += 1

h = h[:m]

for i in range(n):
    if p[f[i]] == -1:
        print(-1)
        exit()
    g[i] = p[f[i]] + 1

print(m)
print(" ".join([str(x) for x in g]))
print(" ".join([str(x) for x in h]))