for tc in range(int(input())):
    n, k = [int(s) for s in input().split()]

    if n % 2 == 1 and k % 2 == 0:
        print('NO')
        continue
    
    if n % 2 == 0 and k % 2 == 1:
        least = 2
    else:
        least = 1

    if least * k > n:
        print('NO')
        continue

    print('YES')
    print(*([n - least*k + least] + [least] * (k-1)))