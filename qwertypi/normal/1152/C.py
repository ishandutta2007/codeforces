import math
def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def GCD(x,y):
    while y!=0:
        z=x%y
        x=y
        y=z
    return x
	
def LCM(x,y):
    return x*y//GCD(x,y)

def factors(n):
    super=[1]
    for i in prime_factors(n):
        super.extend([j*i for j in super])
    return list(sorted(set(super)))

n,m=map(int,input().split())
_factor = factors(abs(n-m))
ans = 0
minimum = math.inf
for i in _factor:
	k = (i-n%i) % i
	if LCM(n+k, m+k) < minimum:
		ans = k
		minimum = LCM(n+k, m+k)
print(ans)