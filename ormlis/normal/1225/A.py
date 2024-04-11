da, db = map(int, input().split())

if da - db == 0:
    print(da * 10, da * 10 + 1)
elif db - da == 1 or (da == 9 and db == 1):
    print(da * 10 + 9, (da + 1) * 10)
else:
    print(-1)