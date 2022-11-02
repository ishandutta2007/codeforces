x=int(input())
b=x**0.5
a=int(b)
p=0
if b==a:
    p-=1
for i in range(1,a+1):
    if x%i==0:
        p+=2
print(p)