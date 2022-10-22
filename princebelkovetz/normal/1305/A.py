for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    b=[int(i) for i in input().split()]
    print (*sorted(a))
    print (*sorted(b))