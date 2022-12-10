#to namiri daram python mizanam =)
def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

n = int(raw_input())
inp = raw_input()
div = 0
mx = 0
for stri in inp.split():
	num = int(stri)
	div = gcd(div, num)
	mx = max(mx, num)

mx /= div
mx -= n
if mx % 2 == 1:
	print "Alice"
else:
	print "Bob"