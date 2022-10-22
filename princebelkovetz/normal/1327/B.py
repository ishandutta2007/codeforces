from sys import stdin, stdout
input=stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    used = [False for i in range(n)]
    v = -1
    for i in range(n):
        l = [int(x) - 1 for x in input().split()][1:]
        for j in l:
            if not used[j]:
                used[j] = True
                break
        else:
            v = i
    if v == -1:
        print("OPTIMAL")
    else:
        u = used.index(False)
        print("IMPROVE\n" + str(v + 1) + " " + str(u + 1) )