x=raw_input().split()
m=int(x[0])
n=int(x[1])
def find(k):
    x=[]
    if k==2:
        x=[3,4]
    elif k%2==0:
        for i in range(k-1):
            x.append(1)
        x.append((k-2)/2)
    else:
        for i in range(k-2):
            x.append(1)
        x.append(2)
        x.append((k+1)/2)
    return x
for i in range(m):
    for t in range(n):
        print find(n)[t]*find(m)[i],
    print '\n'