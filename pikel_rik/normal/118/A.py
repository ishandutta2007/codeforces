s = str(input())
s = s.lower()

vowels = ['a', 'e', 'i', 'o', 'u', 'y']

l = []

for i in s:
    if i not in vowels:
        l.append(i)

for i in range(len(l)):
    if l[i] not in vowels:
        l[i] = '.' + l[i]

s = ''
for i in l:
    s += i

print(s, end = "")