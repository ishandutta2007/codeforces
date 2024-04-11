for tc in range(int(input())):
    n = int(input())
    a = [int(s) for s in input().split()]

    cnt = [0, 0]
    for i, e in enumerate(a):
        if i % 2 != e % 2:
            cnt[i % 2] += 1

    if cnt[0] != cnt[1]:
        print(-1)
    else:
        print(cnt[0])