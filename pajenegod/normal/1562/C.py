import sys
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    B = input()

    #print 'working with B',B, 'with n',n

    def check(a,b,c,d):
        assert 1 <= a <= b <= n
        assert 1 <= c <= d <= n
        
        assert b - a + 1 >= n // 2
        assert d - c + 1 >= n // 2
        
        assert (a,b) != (c,d)
        x = int(B[a-1:b], 2)
        y = int(B[c-1:d], 2)

        assert x == 0 or x % y == 0

        print a,b,c,d


    l = B.find('0') + 1
    if l <= 0 or B.count(B[0]) == n or B == '10':
        a,b,c,d = 2,n, 1,n - 1
        check(a,b,c,d)
    else:
        if n - (l + 1) + 1 >= n // 2:
            a,b,c,d = l,n,l+1,n
            check(a,b,c,d)
        else:
            diff = n // 2 - 1
            
            r = B.rfind('0') + 1
            if r - (diff + 1) >= 1:
                a,b,c,d = r - (diff + 1), r, r - (diff + 1), r - 1
                check(a,b,c,d)
            else:
                a,b,c,d = 2,2 + diff, n - diff, n
                check(a,b,c,d)