x=map(int,raw_input().split())
n=x[0]
m=x[1]
poi=map(int,raw_input().split())
for i in range(m):
    x=raw_input()
st=''
for i in range(n/2):
    st+='01'
if n%2==1:
    st+='0'
dic={}
for i in poi:
    dic[i]=0
for i in sorted(dic.keys()):
    dic[i]=st[0]
    st=st[1:]
for i in poi:
    print dic[i],