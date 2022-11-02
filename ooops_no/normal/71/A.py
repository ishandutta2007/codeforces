l=int(input())
b=0
while b<l:
    w=input()
    if len(w)>10:
        k=w[0],len(w)-2,w[-1]
        p=''
        for i in k:
            p+=str(i)
        print(p)
    else:
        print(w)
    b+=1