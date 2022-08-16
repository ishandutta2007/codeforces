s = str(input())

l = list(s)
d = dict()

c = 0

for i in l:
    d[i] = 1

c = len(d)

if c % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")