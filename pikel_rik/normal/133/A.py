s = str(input())
flag = 0
c = 0
f1 = f2 = f3 = 0

for i in s:
    if i == 'H':
        f1 += 1
    if i == 'Q':
        f2 += 1
    if i == '9':
        f2 += 1

if f1 > 0 or f3 > 0:
    print("YES")
elif f2 > 0:
    print("YES")
else:
    print("NO")