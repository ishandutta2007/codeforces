
import math



n=int(input())
s1=input()
s2=input()

l=len(s1)
svar=0
for i in range(0,l):
    x=abs(int(s1[i])-int(s2[i]))
    y=abs(10-int(s1[i])+int(s2[i]))
    z=abs(int(s1[i])+10-int(s2[i]))
    svar+=min(x,y,z)
print(svar)