import sys
input = sys.stdin.readline
for i in range(int(input())):
    n = int(input())
    k = 2
    x = -1
    while 1:
        if n % (2**k - 1) == 0:
            x = n // (2**k - 1)
            break
        k += 1
    print(x)