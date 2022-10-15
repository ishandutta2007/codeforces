n, b = map(int, raw_input().split())
a = map(int, raw_input().split())
m = max(a)
s = sum(a)
if (s + b) >= n * m:
    one = 1. * (s + b) / n
    for i in range(len(a)):
        print one - a[i]
else:
    print -1