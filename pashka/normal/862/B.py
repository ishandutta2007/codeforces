import collections, sys, threading

sys.setrecursionlimit(10 ** 9)
threading.stack_size(67108864)
de = [0] * 1000000
adjlist = list()
visited = [0] * 1000000
even, odd = 0, 0


def dfs(s, depth):
    global even
    global odd
    de[s] = depth
    visited[s] = 1
    if depth % 2 == 0:
        even = even + 1
    else:
        odd = odd + 1
    for i in range(0, len(adjlist[s])):
        v = adjlist[s][i]
        if visited[v] == 0:
            dfs(v, depth + 1)


def main():
    n = int(input())
    for i in range(0, n + 1):
        adjlist.append(list())
    for i in range(0, n - 1):
        hi = input()
        yo = hi.split()
        a = int(yo[0])
        b = int(yo[1])
        adjlist[a].append(b)
        adjlist[b].append(a)
    dfs(1, 0)
    tot = 0
    for i in range(1, n + 1):
        if de[i] % 2 == 0:
            tot = tot + odd - len(adjlist[i])
        else:
            tot = tot + even - len(adjlist[i])
    print(int(tot / 2))


thread = threading.Thread(target=main)
thread.start()