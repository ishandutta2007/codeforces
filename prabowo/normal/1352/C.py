for tc in range(int(input())):
    n, k = [int(s) for s in input().split()]
    k -= 1
    print(k // (n-1) * n + k % (n-1) + 1)