n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
if (sum(a) != sum(b)):
    print(-1)
else:
    i = 0
    j = 0
    suma = 0
    sumb = 0
    ans = 0
    while (i < n or j < m):
        if (suma == sumb and suma != 0):
            suma = 0
            sumb = 0
            ans += 1
            if (i == n and j == m):
                break
        elif (suma == sumb):
            suma += a[i]
            i += 1
            sumb += b[j]
            j += 1
            if (i == n and j == m):
                break            
        elif (suma < sumb):
            suma += a[i]
            i += 1
        elif (suma > sumb):
            sumb += b[j]
            j += 1
    if (suma == sumb and suma != 0):
        ans += 1
    print(ans)