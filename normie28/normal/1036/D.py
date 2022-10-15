n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
i = j = 0
suma, sumb = a[0], b[0]
if sum(a) != sum(b):
    print(-1)
else:
    arl = 0
    while i < len(a) and j < len(b):
        if suma == sumb:
            arl += 1
            if i == len(a)-1:
                break
            i += 1
            j += 1
            suma += a[i]
            sumb += b[j]
        elif suma < sumb:
            i += 1
            suma += a[i]
        elif sumb < suma:
            j += 1
            sumb += b[j]
    print(arl)