from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    cnt1 = []
    cnt2 = []
    for i in range(2 * n):
        if a[i] % 2 == 1:
            cnt1.append(i)
        else:
            cnt2.append(i)
    # print(cnt1, cnt2)
    if len(cnt1) % 2 == 1:
        cnt1.pop()
        cnt2.pop()
    else:
        if len(cnt1) > 1:
            cnt1.pop()
            cnt1.pop()
        elif len(cnt2) > 1:
            cnt2.pop()
            cnt2.pop()
    for i in range(len(cnt1)):
        print(cnt1[i] + 1, end= " ")
        if i % 2 == 1:
            print()
    for i in range(len(cnt2)):
        print(cnt2[i] + 1, end=" ")
        if i % 2 == 1:
            print()