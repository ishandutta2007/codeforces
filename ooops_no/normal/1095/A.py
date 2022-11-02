x=int(input())
s=input()
st=''
cnt=0
i=1
xopy=x
xopy=0
xopy+=x
while x!=0:
    x-=i
    i+=1
i-=1
while xopy!=0:
    st=st+s[xopy-1]
    xopy-=i
    i-=1
print(st[::-1])