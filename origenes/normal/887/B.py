table=[str(i) for i in range(1, 1000)]
n=int(input())
num=[]
res=[]
for i in range(n):
	s=input()
	s=s.split()
	num.append(s)
#print(num)
for i in num[0]:
	res.append(i)
if n>1:
	for i in num[0]:
		for j in num[1]:
			res.append(str(int(i+j)))
			res.append(str(int(j+i)))
	for i in num[1]:
		res.append(str(int(i)))
if n==3:
	for i in num[0]:
		for j in num[1]:
			for k in num[2]:
				res.append(str(int(i+j+k)))
				res.append(str(int(i+k+j)))
				res.append(str(int(j+i+k)))
				res.append(str(int(j+k+i)))
				res.append(str(int(k+i+j)))
				res.append(str(int(k+j+i)))
	for i in num[2]:
		res.append(str(int(i)))
	for i in num[0]:
		for j in num[2]:
			res.append(str(int(i+j)))
			res.append(str(int(j+i)))
	for i in num[1]:
		for j in num[2]:
			res.append(str(int(i+j)))
			res.append(str(int(j+i)))
#print(res)
for i in range(1, 1001):
	if not (str(i) in res):
		print(i-1)
		break