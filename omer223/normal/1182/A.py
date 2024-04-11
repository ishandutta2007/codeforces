n = int(input())
if n & 1:
    print(0)
else:
    print(1 << (n >> 1))