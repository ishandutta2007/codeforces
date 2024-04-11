import sys


input()
for a in sys.stdin.readlines()[1::2]:
    a = [int(s) for s in a.split()]
    n = len(a)

    can = [False for i in range(n)]
    
    for i in range(1, n):
        s = a[i]
        for j in range(i-1, -1, -1):
            s += a[j]
            if s > n:
                break

            can[s-1] = True

    print(sum([1 for num in a if can[num-1]]))