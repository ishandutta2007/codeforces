n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
s = list(zip(a, b))
s.sort(reverse=True)
i = 0
ans = 0
vz = []
while i < n:
    j = i + 1
    while j < n and s[j][0] == s[i][0]:
        j += 1
    if j - i > 1:
        vz.extend(s[i:j])
    else:
        for e in vz:
            if (e[0] | s[i][0]) == e[0]:
                vz.append(s[i])
                break
    i = j
print(sum(map(lambda x: x[1], vz)))