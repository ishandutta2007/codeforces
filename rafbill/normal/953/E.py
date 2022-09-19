[n] = map(int, input().split())

try:
    xs = map(int, input().split())
except:
    xs = []

stk = []

def push(x):
    while(stk and stk[-1] == x):
        stk.pop()
        x += 1
    stk.append(x)

for x in xs:
    push(x)

print(len(stk))
for x in stk:
    print(x,end=" ")
print("")