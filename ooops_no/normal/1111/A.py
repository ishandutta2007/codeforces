s=input()
t=input()
if len(s)!=len(t):
    print("NO")
else:
    for i in range(len(s)):
        if s[i] in ['a', 'e', 'i', 'o','u']:
            if t[i] in ['a', 'e', 'i', 'o','u']:
                continue
            else:
                print("NO")
                break
        else:
            if t[i] in ['a', 'e', 'i', 'o','u']:
                print("NO")
                break
            else:
                continue
    else:
        print("YES")