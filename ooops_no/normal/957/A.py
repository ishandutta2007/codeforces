x=int(input())
string=input()
i=0
counter=0
right=-1
left=0
counterik=0
if string.count('MM')>=1 or string.count('CC')>=1 or string.count('YY')>=1:
    print("NO")
else:
    while i<x:
        if i==0 and string[i]!='?':
            left=string[i]
            i+=1
            continue
        elif i==0 and string[i]=='?':
            counter+=2
            break
        elif i==x-1:
            if string[-1]=='?':
                counter+=2
            break
        right=string[i+1]
        if string[i]=='?':
            if left==right:
                counter+=2
                break
            elif string[i+1]=='?':
                counter+=2
                break
            else:
                counter+=1
                counterik+=1
            if string[i+1]=='?':
                pass
            else:
                left=string[i+1]
        else:
            left=string[i]
        i+=1
    if counterik==string.count('?'):
        print("NO")
    else:
        if counter>=2:
            print("YES")
        else:
            print("NO")