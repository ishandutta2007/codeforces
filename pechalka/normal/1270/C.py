t = int(input())
for query in range(t):
    n = int(input())
    A = list(map(int, input().split()))
    a = 0
    for c in A:
        a += c
    b = 0
    for c in A:
        b = b ^ c
    print(2, b, a + b)