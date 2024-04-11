m={}
for _ in range(2):
    for i in range(int(input())):
        a,b=map(int,input().split())
        m[a]=max(m.get(a,0),b)
print(sum(m.values()))