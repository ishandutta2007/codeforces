n, bx = map(int, input().split())
xl = list(map(int, input().split()))
kx = bx ** (n - 1)
x = 0
for i in range(n) :
    x += kx * xl[i]
    kx //= bx
n, bx = map(int, input().split())
xl = list(map(int, input().split()))
kx = bx ** (n - 1)
y = 0
for i in range(n) :
    y += kx * xl[i]
    kx //= bx
if x < y :
    print("<")
elif x > y :
    print(">")
else :
    print("=")