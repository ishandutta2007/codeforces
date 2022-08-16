s1 = str(input())
s2 = str(input())
s3 = str(input())

s = "abcdefghijklmnopqrstuvwxyz"
s = s.upper()

d1 = dict()
d2 = dict()
for i in s:
    d1[i] = 0
    d2[i] = 0

for i in s1:
    d1[i] += 1
for i in s2:
    d1[i] += 1
for i in s3:
    d2[i] += 1

flag = 0
for i in d1:
    if d1[i] != d2[i]:
        flag = 1
        break

if flag == 0:
    print("YES")
else:
    print("NO")