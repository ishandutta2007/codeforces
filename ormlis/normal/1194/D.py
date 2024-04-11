def solve():
    n, k = map(int, input().split())
    if k % 3:
        if n % 3 == 0:
            print("Bob")
        else:
            print("Alice")
    else:
        k += 1
        n %= k
        if n == k - 1:
            print("Alice")
        elif n % 3 == 0:
            print("Bob")
        else:
            print("Alice")


for _ in range(int(input())):
    solve()