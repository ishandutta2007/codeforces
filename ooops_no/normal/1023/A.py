len1,len2=map(int,input().split())
a=input()
b=input()
if "*" not in a:
    if a==b:
        print("YES")
    else:
        print("NO")
else:
    string1=a[0:a.index('*')]
    string2=a[a.index('*')+1:]
    if len(string1)+len(string2)>len2:
        print("NO")
    else:
        if string1 in b and string2 in b:
            if b.index(string1)==0:
                i=1
                while i<=len(string2):
                    if b[-i]==string2[-i]:
                        i+=1
                    else:
                        print("NO")
                        break
                else:
                    print("YES")
            else:
                print("NO")
        else:
            print("NO")