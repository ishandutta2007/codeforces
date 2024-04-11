K = [0]*1000

K[0] = 1
for i in range(1, 1000):
    K[i] = i*K[i-1]

M = {}

def F(a,b):
    if a == 0 and b == 0:
        return 1
    if b == 0:
        return K[a]
    if (a,b) in M:
        return M[(a,b)]
    t = 0
    if a > 0:
        t += a*F(a-1,b)
    t += F(a,b-1)
    if b > 1:
        k = b-1
        for i in range(0,a+1):
            t += k*F(a-i,b-2)
            k *= (a-i)
    M[(a,b)] = t
    return t

n = int(raw_input())

d = [int(x) for x in raw_input().split(" ")]

x = 0
y = 0

for i in range(n):
    if d[i] == 1:
        x += 1
    if d[i] == 2:
        y += 1

print F(y,x)