def ana(st):
    ans=1
    an=' 1x12'
    if st=='XXXXXXXXXXXX':
        return '6 1x12 2x6 3x4 4x3 6x2 12x1'
    if st=='OOOOOOOOOOOO':
        return '0'
    for i in range(6):
        if st[i]==st[i+6]=='X':
            ans+=1
            an+=' 2x6'
            break
    for i in range(4):
        if st[i]==st[i+4]==st[i+8]=='X':
            ans+=1
            an+=' 3x4'
            break
    if st[::3]=='XXXX' or st[1::3]=='XXXX' or st[2::3]=='XXXX':
        ans+=1
        an+=' 4x3'
    if st[::2]=='XXXXXX' or st[1::2]=='XXXXXX':
        ans+=1
        an+=' 6x2'
    return str(ans)+an
lis=[]
n=input()
for i in range(n):
    lis.append(raw_input())
for i in lis:
    print ana(i)