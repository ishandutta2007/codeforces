for tc in range(int(input())):
    a, k = [int(s) for s in input().split()]
    while min(str(a)) != '0' and k > 1:
        a, k = a + int(min(str(a))) * int(max(str(a))), k - 1
    print(a)