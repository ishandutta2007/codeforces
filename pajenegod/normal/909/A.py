a,b = input().split()
n=len(a)
m=len(b)
names = []
for i in range(n):
    for j in range(m):
        names.append(a[:i+1]+b[:j+1])
print(min(names))