x=int(input())
listik=list(map(int,input()))
summa=sum(listik)
if len(listik)%x==0:
    x=True
    for i in listik:
        if i==listik[0]:
            pass
        else:
            break
    else:
        x=False
        print("YES")
        
if x:
    for i in range(1,summa//2+1):
        if summa%i==0:
            SumMin=0
            for j in listik:
                if SumMin+j>i:
                    break
                elif SumMin+j==i:
                    SumMin=0
                else:
                    SumMin+=j
            else:
                if SumMin==0 or SumMin==i:
                    print("YES")
                    break
    else:
        print("NO")