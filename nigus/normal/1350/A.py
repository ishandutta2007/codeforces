t = int(input())

for case in range(t):
    n, k = map(int, input().split())
    found = False
    for i in range(2, int(n**0.5) + 2):
        if n % i == 0:
            found = True
            n += i
            break
    if not found:
        n *= 2
    n += (k-1)*2
    print(n)