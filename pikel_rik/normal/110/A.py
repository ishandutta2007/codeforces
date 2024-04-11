s = str(input())
c = 0

for i in s:
    if i == '4' or i == '7':
        c += 1

c = str(c)
flag = 0

for i in c:
    if i != '4' and i != '7':
        flag = 1

if flag == 1:
    print("NO")
else:
    print("YES")