for _ in range(int(input())):
    s=input()
    cou=0
    cou1=0
    for i in range(len(s)):
        if s[i] =='R':
            if cou>cou1:
                cou1=cou
            cou=0
        elif s[i]=='L':
            cou+=1
    if cou > cou1:
        cou1 = cou
    print(cou1+1)