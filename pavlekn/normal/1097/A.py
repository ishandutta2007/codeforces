s = input()
a = s[0]
b = s[1]
q = input().split()
ans = "NO"
for el in q:
    if (el[0] == a or el[1] == b):
        ans = "YES"
print(ans)