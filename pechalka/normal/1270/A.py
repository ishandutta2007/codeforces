t = int(input())
for query in range(t):
    n, k1, k2 = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    if n in A:
        print("YES")
    else:
        print("NO")