a,b,c=map(int,input().split())
str1=input()
str2=input()
string=''
for i in range(a-b+1):
    if str1[i:i+b]==str2:
        string+='1'
    else:
        string+='0'
for _ in range(c):
    x,y=map(int,input().split())
    if y-x+1>=b:
        print(string[x-1:y-b+1].count('1'))
    else:
        print(0)