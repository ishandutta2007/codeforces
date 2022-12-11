n = int(input())
s = set()
a = list(map(int, input().split()))
for el in a:
    if (el != 0):
        s.add(el)
print(len(s))