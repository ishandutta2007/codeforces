x=int(input())
a=input()
b=a.count("8")
if b>0 and b<=x//11:
    print(b)
elif b>0 and b>=x//11:
    print(x//11)
else:
    print(0)