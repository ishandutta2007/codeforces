x=raw_input()
lis='AHIMOTUVWXY'
ans=True
for i in x:
    if i not in lis:
        ans=False
        break
if not x==x[::-1]:
    ans=False
if ans:
    print 'YES'
else:
    print 'NO'