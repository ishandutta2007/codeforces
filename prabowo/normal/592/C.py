def gcd(x, y) :
	if (y) : return gcd(y, x % y)
	return x

t, w, b = map(int, input().split())

kpk = w * b // gcd(w, b)

ans = (t // kpk + 1) * min(w, b) - 1
ans -= max(0, min(w, b) - t % kpk - 1)

fpb = gcd(ans, t)

print(ans // fpb, "/", t // fpb, sep = "")