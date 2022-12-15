x=map(int,raw_input().split())
n=x[0]
k=x[1]
cou=0
x=map(int,raw_input().split())
for i in x:
    if i+k<=5:
        cou+=1
print cou/3