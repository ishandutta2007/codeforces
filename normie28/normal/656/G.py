n,p,a,r,kitten=range,input,[],0,0
F,I,T=map(int,p().split())
for i in n(F):a.append(p())
for i in n(I):
    c=0
    for j in n(F):
        c+=a[j][i]=='Y'
    if c>=T:r+=1
print(r)