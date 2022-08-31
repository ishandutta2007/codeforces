n = int(input())

s = str(input())
s = s.lower()

s1 = "abcdefghijklmnopqrstuvwxyz"
l = list(s1)

d = dict()
for i in l:
    d[i] = 0

for i in s:
    d[i] += 1

flag = 0
for i in d:
    if d[i] == 0:
        flag = 1

if flag == 0:
    print("YES")
else:
    print("NO")