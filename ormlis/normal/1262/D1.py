n = int(input())
arr = list(map(int, input().split()))
m = int(input())
arr2 = sorted((el, -i) for i, el in enumerate(arr))
for _ in range(m):
    k, pos = map(int, input().split())
    arr3 = sorted(arr2[-k:], key=lambda x: -x[1])
    print(arr3[pos - 1][0])