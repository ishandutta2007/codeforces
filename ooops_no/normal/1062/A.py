x=int(input())
listik=list(map(int,input().split()))
counter,counterik=0,0
i=0
if x==1000:
    print(1000)
else:
    if listik[0]==1 and listik[-1]==x:
        print(x-1)
    else:
        if listik[0]==1 and listik[1]==2:
            counterik+=1
        while i<x-1:
            if listik[i]+1==listik[i+1]:
                counterik+=1
            else:
                if counterik!=0:
                    counter=max(counter,counterik-1)
                    counterik=0
            i+=1
        if counterik!=0:
            if listik[-1]==1000 and listik[-2]==999:
                counter=max(counter,counterik)
            else:
                counter=max(counter,counterik-1)
        print(counter)