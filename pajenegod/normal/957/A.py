import sys
xrange = range
input = raw_input

n = int(input())
S = [c for c in input()]
for i in range(1,n):
    if S[i-1]!='?' and S[i]!='?' and S[i]==S[i-1]:
        print('No')
        sys.exit()
for i in range(1,n):
    if S[i-1]=='?' and S[i]=='?':
        print('Yes')
        sys.exit()
if S[-1]=='?' or S[0]=='?':
    print('Yes')
    sys.exit()
for i in range(1,n-1):
    if S[i-1]==S[i+1] and S[i]=='?':
        print('Yes')
        sys.exit()
print('No')

#s = 'CMY'
#D = {}
#D['C']=0
#D['M']=1
#D['Y']=2
#locked = ['?'==S[i] for i in range(n)]
#
#if S[0]=='?':
#    pos[0] = 1
#else:
#    pos[0] = 0
#for i in range(1,n):
#    if S[i]=='?':
#        temp = pos[i-1][:]
#        temp = [1-t for t in ]