n=input()
st=raw_input()
x=st.count('x')
y=n-x
if x==n/2:
    print 0
    print st
elif x<n/2:
    dif=n/2-x
    print dif
    i=0
    while dif!=0:
        if st[i]=='X':
            st=st[:i]+'x'+st[i+1:]
            dif-=1
        i+=1
    print st
else:
    dif=x-n/2
    print dif
    i=0
    while dif!=0:
        if st[i]=='x':
            st=st[:i]+'X'+st[i+1:]
            dif-=1
        i+=1
    print st