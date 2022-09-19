t = int(input())
for i in range(t):
    n = int(input())
    s = 3
    k = 2
    while n % s != 0:
        k *= 2
        s += k
    print(n // s)