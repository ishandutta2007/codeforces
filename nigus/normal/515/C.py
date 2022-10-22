import math
import sys

n=int(input())
s=input()
v=[]
for i in range(0,n):
    if s[i] == '2':
        v.append(2)
    if s[i] == '3':
        v.append(3)
    if s[i] == '4':
        v.append(2)
        v.append(2)
        v.append(3)
    if s[i] == '5':
        v.append(5)
    if s[i] == '6':
        v.append(5)
        v.append(3)
    if s[i] == '7':
        v.append(7)
    if s[i] == '8':
        v.append(7)
        v.append(2)
        v.append(2)
        v.append(2)
    if s[i] == '9':
        v.append(7)
        v.append(2)
        v.append(3)
        v.append(3)
        
        
v.sort()
m=0
t=1
for i in range(0,len(v)):
    m+=v[i]*t
    t*=10
print(m)