n = int(input())
summa = 0
first = True
while n>0 or first:
    first = False
    x = n%16
    n //= 16
    if x==4 or x==0 or x==6 or x==9 or x==10 or x==13:
        summa += 1
    if x==8 or x==11:
        summa += 2
print(summa)