n,m=map(int,raw_input().split())
s1=raw_input()
s2=raw_input()
if (s1[0]=='<' and s2[0]=='^') or (s1[0]=='>' and s2[-1]=='^') or (s1[-1]=='<' and s2[0]=='v') or (s1[-1]=='>' and s2[-1]=='v'):
    print 'NO'
else:
    print 'YES'