s=input()
x=int(input())
if '*' not in s:
    if len(s)-s.count('?')<x or len(s)-s.count('?')*2>x: 
        print("Impossible")
    else:
        need=len(s)-s.count('?')-x
        i=0
        while i<len(s):
            if s[i]=='?':
                if need!=0:
                    s=s[:i-1]+s[i+1:]
                    need-=1
                    i-=1
                else:
                    s=s[:i]+s[i+1:]
                    i-=1
            else:
                i+=1
        print(s)
else:
    if len(s)-(s.count('?')+s.count('*'))*2>x:
        print("Impossible")
    else:
        i=0
        cnt=s.count('*')
        while i<len(s):
            if s[i]=='?':
                s=s[:i-1]+s[i+1:]
                i-=1
            elif s[i]=='*':
                if cnt!=1:
                    s=s[:i-1]+s[i+1:]
                    cnt-=1
                    i-=1
                else:
                    i+=1
            else:
                i+=1
        need=x-(len(s)-1)+1
        ind=s.index('*')
        s=s[:ind-1]+s[ind-1]*need+s[ind+1:]
        print(s)