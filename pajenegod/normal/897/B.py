k,p = [int(x) for x in input().split()]
found = 0
numb = 1
summa = 0
while found < k:
    temp = str(numb)
    dum = int(temp+"".join(reversed(temp)))
    summa += dum
    found += 1
    numb += 1
print(summa%p)