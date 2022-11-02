a,b=map(int,input().split())
listik1=list(map(int,input().split()))
listik2=list(map(int,input().split()))
if listik1[0]==0:
    print("NO")
else:
    if listik1[b-1]==0 and listik2[b-1]==0:
        print("NO")
    else:
        if listik1[b-1]==1:
            print("YES")
        else:
            if listik2[b-1]==1:
                for _ in range(b,a):
                    if listik1[_]==1 and listik2[_]==1:
                        print("YES")
                        break
                else:
                    print("NO")
            else:
                print("NO")