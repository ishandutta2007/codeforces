n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
i = 0
s1 = a[i]
j = 0
s2 = b[j]
ans = 0
while (i < n and j < m):
    if (s2 < s1):
        while (s2 < s1):
            j += 1
            s2 += b[j]
    elif (s1 < s2):
        while (s1 < s2):
            i += 1
            s1 += a[i]
    if (s1 == s2):
        ans += 1
        j += 1
        i += 1
        if (i < n and j < m):
            s1 = a[i]
            s2 = b[j]        
print(ans)