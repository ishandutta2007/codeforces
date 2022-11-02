x=input()
lens=len(x)
if lens%2==0:
    mid=lens//2-1
else:
    mid=lens//2
mid1,mid2=0,0
mid1+=mid-1
mid2+=mid+1
st=x[mid]
for i in range(lens-1):
    if i%2==0:
        st+=x[mid2]
        mid2+=1
    else:
        st+=x[mid1]
        mid1-=1
print(st)