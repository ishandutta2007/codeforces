#from sys import stdin, stdout, setrecursionlimit
#input = stdin.readline
#print = stdout.write

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = [int(i) for i in input().split()]
    if len(set(a)) > k:
        print(-1)
    else:
        b = []
        r = set(a)
        j = 1
        while len(r) < k:
            r.add(j)
            j += 1

        for elem in r:
            b.append(elem)
        b *= n
        print(len(b))
        print(*b)