n=input()
s=map(int,raw_input().split())
dic={i:[] for i in range(1,2001)}
c=0
for i in range(n):
    dic[s[i]].append(i+1)
    if len(dic[s[i]])>1:
        c+=1
if c<2:
    print 'NO'
else:
    print 'YES'
    for i in dic:
        for j in dic[i]:
            print j,
    print '\n'
    flag=False
    m1=0
    for i in dic:
        if len(dic[i])>2:
            flag=True
            m1=i
            break
    if not flag:
        d=0
        m=[]
        for i in dic:
            if len(dic[i])>1:
                d+=1
                m.append(i)
            if d==2:
                break
        for i in range(1,m[0]):
            for j in dic[i]:
                print j,
        print dic[m[0]][1],dic[m[0]][0],
        for i in range(m[0]+1,m[1]):
            for j in dic[i]:
                print j,
        print dic[m[1]][1],dic[m[1]][0],
        for j in dic[m[1]][2:]:
            print j,
        for i in range(m[1]+1,2001):
            for j in dic[i]:
                print j,
        print '\n'
        for i in range(1,m[0]):
            for j in dic[i]:
                print j,
        print dic[m[0]][1],dic[m[0]][0],
        for i in range(m[0]+1,2001):
            for j in dic[i]:
                print j,
        print '\n'
    else:
        for i in range(1,m1):
            for j in dic[i]:
                print j,
        print dic[m1][1],dic[m1][0],dic[m1][2]
        for i in dic[m1][3:]:
            print i,
        for i in range(m1+1,2001):
            for j in dic[i]:
                print j,
        print '\n'
        for i in range(1,m1):
            for j in dic[i]:
                print j,
        print dic[m1][1],dic[m1][2],dic[m1][0]
        for i in dic[m1][3:]:
            print i,
        for i in range(m1+1,2001):
            for j in dic[i]:
                print j,
        print '\n'