n,m = [int(x) for x in input().split()]
s = [c for c in input()]
oper = []
for _ in range(m):
    a,b,c,d = input().split()
    a = int(a)
    b = int(b)
    oper.append((a,b,c,d))

for op in oper:
    l,r,c1,c2 = op
    for i in range(l-1,r):
        if s[i]==c1:
            s[i] = c2
print("".join(s))