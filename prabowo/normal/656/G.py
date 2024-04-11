F,I,T=map(int,input().split())
a=[0 for i in range(I)]
for i in range (F):
	s=input()
	for j in range(I):a[j]+=s[j]=='Y'
s=0
for v in a:s+=v>=T
print(s)#kitten