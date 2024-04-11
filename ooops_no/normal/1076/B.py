x=int(input())
i=2
while i*i<=x:
    if x%i==0:
        break
    else:
        i+=1
else:
    i=x
print(1+(x-i)//2)