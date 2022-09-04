def f(x, l):
    return (45 * l + 10 * x) * (10 ** (l-1))

a = int(input())
L = 1
x = 0
if a < 10000 : a *= 10000
while f(x, L + 1) < a : 
    L += 1
while f(x + 1, L) < a : 
    x += 1
now = f(x, L)
add = a - now

di = 0
t = 0
while(di < x):
    if di + 9 <= x : 
        t = t * 10 + 9
        di += 9
    else:
        t = t * 10 + (x - di)
        di = x

t *= 10
l = t * (10 ** L) + add
r = (t + 1) * (10 ** L) + add - 1
print(l, r)