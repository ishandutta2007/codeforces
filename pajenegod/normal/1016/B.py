import sys
def get_array(): return list(map(int, sys.stdin.readline().split()))
def get_ints(): return map(int, sys.stdin.readline().split())
def input(): return sys.stdin.readline().strip('\n')

n , m , q = get_ints()
s = input()
p = input()

ans = []
i = 0
count = 0
while True:
    si = s.find(p,i)
    if si != -1:
        ans += [count]*(si-i+1)
        count += 1
        i = si+1
    else:
        ans += [count]*(n-i+2)
        break

out = []
for i in range(q):
    a , b = get_ints()
    a -= 1
    b -= m-1
    out.append(ans[b]-ans[a] if b >= a else 0)

print(*out,sep='\n')