n=input()
d=(n-1)
kit=[]
home={i:0 for i in range(100001)}
for i in range(n):
    t=map(int,raw_input().split())
    x=t[0]
    y=t[1]
    kit.append(y)
    home[x]+=1
for i in kit:
    f=home[i]
    print d+f,d-f