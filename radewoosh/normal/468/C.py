import random
import sys

def f(n, mod):
	l=[]
	while n>0:
		l.append(n%10)
		n//=10
	ret=0
	num=0
	suma=0
	war=1
	for i in l:
		a=0
		b=0
		
		for j in range(i):
			a=(a+suma+j*war)%mod
		a=(a+ret+i*(num+1))%mod
		
		for j in range(10):
			b=(b+suma+j*war)%mod
		
		ret=a
		suma=b
		
		num=(num+war*i)%mod
		war=(war*10)%mod
	return ret

def los(dlu):
	ret=0
	for i in range(dlu):
		ret=ret*10+random.randint(0, 9)
	return ret

def ans(a, b):
	print(a, b)
	sys.exit(0)

pam=[(0, 0)]

mod=int(input())

while True:
	a=los(42)
	b=a+los(20)
	if a==b:
		continue
	if a>b:
		a,b=b,a
	wa=f(a, mod)
	wb=f(b, mod)
	if wa==wb:
		ans(a+1, b)
	if wa<wb:
		continue
	#~ print("jade")
	while a+1<b:
		s=(a+b)//2
		ws=f(s, mod)
		#~ if ws==0:
			#~ ans(1, s)
		if ws<=wb:
			b=s
			wb=ws
		else:
			a=s
			wa=ws
	for i in pam:
		if i[1]==wb:
			ans(min(i[0], b)+1, max(i[0], b))
	pam.append((b, wb))