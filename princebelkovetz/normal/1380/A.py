for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    ans = []
    for i in range(1, n - 1):
        if a[i - 1] < a[i] and a[i] > a[i + 1]:
            ans = [i - 1, i, i + 1]
    if len(ans) > 0:
        print("YES")
        for x in ans:
            print (x + 1, end = " ")
        print()
    else: print("NO")