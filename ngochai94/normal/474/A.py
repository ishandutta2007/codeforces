l1='qwertyuiop'
l2='asdfghjkl;'
l3='zxcvbnm,./'
l=l1+l2+l3
d=raw_input()
s=raw_input()
if d=='L':
    ans=''
    for i in s:
        d=l.find(i)
        ans+=l[d+1]
else:
    ans=''
    for i in s:
        d=l.find(i)
        ans+=l[d-1]
print ans