s = str(input())

l = list(s)

j = 0
s1 = "helloa"
t = s1[j]

for i in range(len(l)):
    if t == 'a':
        break
    if l[i] == t:
        j += 1
        t = s1[j]

if t != 'a':
    print("NO")
else:
    print("YES")