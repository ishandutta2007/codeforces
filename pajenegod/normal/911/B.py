n,a,b = [int(x) for x in input().split()]
for x in reversed(range(1,1000000)):
    if a//x + b//x >= n and a//x>0 and b//x > 0:
        print(x)
        break