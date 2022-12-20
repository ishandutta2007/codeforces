F,I,T = raw_input().split()
F = int(F)
I = int(I)
T = int(T)
a = [0]*I
ans=0
kitten=0
for i in range(F):
    s = raw_input()
    for j in range(I):
        if(s[j]=='Y'):
            a[j]+=1
            ans += (a[j]==T)
print ans