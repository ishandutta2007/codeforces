def binser(lis,val):
    hi=len(lis)-1
    lo=0
    while hi!=lo:
        ind=(hi+lo)/2
        if lis[ind]>=val:
            hi=ind
        else:
            lo=ind+1
    return hi
n=input()
a=map(int,raw_input().split())
s=[0]
for i in a:
    s.append(s[-1]+i)
m=input()
q=map(int,raw_input().split())
for j in q:
    print binser(s,j)