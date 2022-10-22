for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    a=sorted(a, reverse=True)
    print(*a)