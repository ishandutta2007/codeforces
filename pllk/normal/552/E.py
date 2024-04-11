x = raw_input()
x = "1*"+x+"*1"
z = []
for i in range(len(x)):
    if x[i] == '*':
        z.append(i)
p = 0
for i in range(len(z)):
    a = z[i]
    for j in range(i+1,len(z)):
        b = z[j]
        u = x[:a+1] + "(" + x[a+1:b] + ")" + x[b:]
        p = max(p,eval(u))
print p