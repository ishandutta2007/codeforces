a, b, c, n = map(int, input().split())

ans = n - (a + b - c)

err = False
if ans < 1: err = True
if c > min(a, b): err = True

if err: 
    print (-1)
else:
    print (ans)