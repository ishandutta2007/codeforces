def main():
    n = int(input())
    ans1 = 0
    ans2 = 0
    a = list(map(int, input().split()))
    a.sort()
    b1 = []
    b2 = []
    for i in range(1, n + 1):
        if (i % 2 == 0):
            b1.append(i)
        else:
            b2.append(i)
    for i in range(n // 2):
        ans1 += abs(a[i] - b1[i])
    for i in range(n // 2):
        ans2 += abs(a[i] - b2[i])    
    print(min(ans1, ans2))
main()