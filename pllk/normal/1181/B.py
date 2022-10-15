n = int(input())
s = input()

def lol(k):
	global s, n, u
	if k <= 0 or k >= n or s[k] == '0':
		return
	x = s[0:k]
	y = s[k:]
	u = min(u,int(x)+int(y))

a = n//2
while a-1 >= 0 and s[a] == '0':
	a -= 1
b = n//2
while b+1 <= n-1 and s[b] == '0':
	b += 1
u = int(s)
for i in range(-3,4):
	lol(a+i)
	lol(b+i)
print(u)