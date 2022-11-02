string=input()
counter=0
countera=0
counterb=0
for i in string:
    if i=='a':
        counter+=countera+1
        counter%=1e9+7
    elif i=='b':
        countera=counter
print(int(counter%(1e9+7)))