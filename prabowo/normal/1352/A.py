for tc in range(int(input())):
    n = int(input())

    ten, ans = 1, []
    for i in range(5):
        ten *= 10
        if n % ten > 0:
            ans.append(n % ten)
            n -= n % ten

    print(len(ans))
    print(*ans)