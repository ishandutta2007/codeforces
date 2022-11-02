x=int(input())
f = [0]*(x+1)
o , w = 0 , 0
for i in input().split():
    f[int(i)] = o+1
    o+=1
for i in input().split():
    i=int(i)
    if f[i]>w:
        print(f[i]-w,end=" ")
        w=f[i]
    else:
        print(0,end=" ")