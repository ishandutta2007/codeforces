import math as m

s = input()
lis = s.split()

t = int(lis[0])
w = int(lis[1])
b = int(lis[2])

if w > b:
    w, b = b, w

num = (w * b) // m.gcd(w, b)
c = t // num

ans = c * w

if ans > num * c + w - 1 - t and t < num * c + w - 1:
    ans -= num * c + w - 1 - t

ans += min(t, w - 1)

print(ans // m.gcd(ans, t), end="")
print("/", end="")
print(t // m.gcd(t, ans))