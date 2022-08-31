a = list(map(int, input().split()))

s = sum(a)
if s % 2:
    print("NO")
else:
    f = s // 2
    if f - a[0] in a[1:] or f in a:
        print("YES")
    else:
        print("NO")