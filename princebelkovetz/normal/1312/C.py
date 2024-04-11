for _ in range(int(input())):
    def fm(a):
        jj=a[0]
        j=0
        for i in range(1,len(a)):
            if a[i]>jj:
                jj=a[i]
                j=i
        return j
    n,k = map(int,input().split())
    a = [int(i) for i in input().split()]
    s = 0
    d = max(a)

    while k ** s < d:
        s += 1

    check = True
    for i in range(s+1):
        while k**s>a[fm(a)]:
            s-=1
        a[fm(a)] -= k**s
        s -= 1
        if a[fm(a)]>k**s:
            check=False
    if check or sum(a)==0:
        print('YES')
    else:
        print("NO")