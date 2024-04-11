s = str(input())

v = [int(s[i]) for i in range(len(s)) if s[i].isdigit()]

v.sort()

for i in range(len(v)-1):
    print(v[i], end = '+')

print(v[len(v)-1])