def ae(arr2, arr1, k):
    k //= 2
    cur = set(map(lambda x: arr[x], arr1))
    ans = []
    c = 0
    for e in arr2:
        s = arr[e][::-1]
        if s not in cur:
            ans.append(e + 1)
            c += 1
        if c == k:
            break
    if c < k:
        print(-1)
    else:
        print(k)
        print(*ans)


def solve():
    n = int(input())
    arr.clear()
    arr1 = []
    arr2 = []
    f = 0
    for i in range(n):
        a = input()
        if a[0] != a[-1]:
            if a[0] == '1':
                arr1.append(i)
            else:
                arr2.append(i)
        elif a[0] == '0' and f % 10 == 0:
            f += 1
        elif a[0] == '1' and f // 10 == 0:
            f += 10
        arr.append(a)
    k = abs(len(arr2) - len(arr1))
    if k >1 :
        if len(arr2) > len(arr1):
            ae(arr2, arr1, k)
        else:
            ae(arr1, arr2, k)
    elif len(arr2) == len(arr1) == 0 and f // 10 and f % 10:
        print(-1)
    else:
        print(0)


t = int(input())
arr = []
for _ in range(t):
    solve()