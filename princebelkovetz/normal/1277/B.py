for _ in range (int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    ans = set()
    for i in range(n):
        while a[i] % 2 == 0:
            ans.add(a[i])
            a[i] //= 2
    print(len(ans))