import math
n=int(input())
s=input()
f=[0]*(3)
for i in s:
	if i=='0':
		f[0]+=1
	if i=='1':
		f[1]+=1
	if i=='2':
		f[2]+=1
rr=(n//3)
arr=[]
for i in s:
	arr.append(i)
for i in range(n):
	cur=int(s[i])
	if f[cur]>rr:
		for j in range(0,cur):
			if f[j]<rr:
				arr[i]=str(j)
				f[j]+=1
				f[cur]-=1
				break
for i in range(n-1,-1,-1):
	cur=int(s[i])
	if f[cur]>rr:
		for j in range(2,-1,-1):
			if j==cur:
				continue
			if f[j]<rr:
				arr[i]=str(j)
				f[j]+=1
				f[cur]-=1
				break
# print(arr)
print(''.join(arr))