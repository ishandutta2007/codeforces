for _ in range (int(input())):
    n = int(input())
    if int(str(n)[0] * len(str(n))) > n:
        ans = int(str(n)[0]) - 10 + len(str(n)) * 9
    else:
        ans = int(str(n)[0]) - 9 + len(str(n)) * 9
    print(ans)