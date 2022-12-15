lis=[]
ans=['A','B','C','D']
for i in range(4):
    lis.append(len(raw_input())-2)
an=sorted(lis[:])
mi=0
ma=0
if 2*an[0]<=an[1]:
    mi=1
if 2*an[2]<=an[3]:
    ma=1
if mi==0 and ma==0:
    print 'C'
elif mi==1 and ma==1:
    print 'C'
elif mi==1:
    for i in range(4):
        if lis[i]==an[0]:
            print ans[i]
else:
    for i in range(4):
        if lis[i]==an[-1]:
            print ans[i]