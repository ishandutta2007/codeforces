a,b = map(int,raw_input().split())
n = int(raw_input())
k = b-a
if n%6 == 1:
	print a%1000000007
if n%6 == 2:
	print b%1000000007
if n%6 == 3:
	print k%1000000007
if n%6 == 4:
	print (-a)%1000000007
if n%6 == 5:
	print (-b)%1000000007
if n%6 == 0:
	print (-k)%1000000007