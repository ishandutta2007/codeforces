x=raw_input().split()
y=raw_input().split()
for i in range(len(y)):
    y[i]=int(y[i])
for i in range(int(x[1])-1):
    y.remove(max(y))
print max(y)