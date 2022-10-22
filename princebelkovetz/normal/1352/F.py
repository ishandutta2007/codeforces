from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n1, n2, n3 = map(int, input().split())
    x = ''
    while n1 + n2 + n3 > 0:
        if n3 > 0:
            x += '1'
            n3 -= 1
            if n3 == 0:
                x += '1'
        elif n1 > 0:
            x += '0'
            n1 -= 1
            if len(x) >= 2:
                if x[-2] == '1':
                    n2 -=1
            if n1 == 0:
                x += '0'
        elif n2 > 0:
            if len(x) == 0:
                x += '0'
            else:
                if x[-1] == '1':
                    x += '0'
                else:
                    x += '1'
                n2 -= 1

        #print(n1, n2, n3)
    print(x)