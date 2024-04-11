a=int(input())
b=a//3
c=a//3
while True:
    if b%3==0:
        b+=1
        c-=1
    if c%3==0:
        c+=2
        b-=2
    else:
        break
d=a-(b+c)
while True:
    if d%3==0:
        d+=1
        c-=1
    if c%3==0:
        c+=2
        d-=2
    else:
        break
print(b,c,d)