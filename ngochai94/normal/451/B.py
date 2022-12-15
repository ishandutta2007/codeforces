n=input()
lis=map(int,raw_input().split())
an=sorted(lis)
for st in range(n):
    if lis[st]!=an[st]:
        break
for en in range(n-1,-1,-1):
    if lis[en]!=an[en]:
        break
if st>=en:
    print 'yes'
    print '1 1'
else:
    if lis[st:en+1]==an[st:en+1][::-1]:
        print 'yes'
        print st+1,en+1
    else:
        print 'no'