n=input()
done=False
for _ in range(4):
    a,b,c,d=map(int,raw_input().split())
    if a+c<=n:
        print _+1,a,n-a
        done=True
        break
    if a+d<=n:
        print _+1,a,n-a
        done=True
        break
    if b+c<=n:
        print _+1,b,n-b
        done=True
        break
    if b+d<=n:
        print _+1,b,n-b
        done=True
        break
if not done:
    print -1