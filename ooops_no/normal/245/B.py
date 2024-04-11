x=input()
s=''
if 'ftp' in x:
    if x.index("ftp")==0:
        s="ftp://"
        x=x[3:]
    else:
        s="http://"
        x=x[4:]
else:
    s="http://"
    x=x[4:]
index=x.index("ru")
if index==0:
    x=x[2:]
    index=x.index("ru")
    s+="ru"+x[:index]+".ru"
else:
    s+=x[:index]+".ru"
if x[index+2:]!='':
    s+="/"+x[index+2:]
print(s)