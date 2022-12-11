n = int(input())
a = list(map(int, input().split()))
a.reverse()
s = set()
ans = []
for el in a:
    if (el not in s):
        s.add(el)
        ans.append(el)
ans.reverse()
print(len(s))
for el in ans:
    print(el, end=' ')