n = int(input())
l = list(map(int,input().split()))
x = []
l.reverse()
for i in l:
    if i not in x:
        x.append(i)
x.reverse()
print(len(x))
print(*x)