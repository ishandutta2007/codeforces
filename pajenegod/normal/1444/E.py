import sys
input = raw_input

"""
You have to solve a problem: you are given an array a1,a2,,ak of long binary numbers. You have to find an array with the smallest sum b1,b2,,bk such that bi>=ai, and no carries will happen during the addition b1+b2++bk.
Same as https://codeforces.com/gym/102154/problem/A
"""
def solver(A):
    # Check if sum = 0b1111...11 (k ones) is possible
    def solve(A, k):
        if not A or k < 0:
            return True
        count = 0
        for a in A:
            if a >> k > 1:
                return False
            count += a >> k
        if count >= 2:
            return False
        
        if count == 0:
            i = max(range(len(A)), key = A.__getitem__)
            A.pop(i)
            return solve(A, k - 1)
        else:
            return solve([a ^ ((a >> k) << k) for a in A], k - 1)

    ans = 0
    B = A[:]
    A = A[:]
    while any(A):
        k = max(a.bit_length() - 1 for a in A)
        while not solve([a for a in A if a], k):
            k += 1
        
        count = 0
        for a in A:
            count += a >> k
        
        if count == 0:
            i = max(range(len(A)), key = A.__getitem__)
            A[i] = 0
            B[i] = ((B[i] >> k) | 1) << k
        else:
            A = [a ^ ((a >> k) << k) for a in A]
    return B

# Returns the shallowest possible edge decomposition
def shallowest_edge_tree_decomposition(graph):
    n = len(graph)
    decomposition_tree = [[] for _ in range(n)]
    dp1 = [0] * n
    dp2 = [0] * n
    def dfs1(u, p):
        A = []
        for v in graph[u]:
            if v != p: 
                dfs1(v, u)
                A.append(dp1[v])
        B = solver([a + 1 for a in A])
        for v in reversed(graph[u]):
            if v != p: 
                dp2[v] = B.pop()
                dp1[u] |= dp2[v]
    
    stacks = [[] for _ in range(n)]
    def create_chain(labels, u):
        while labels:
            label = labels.bit_length() - 1
            labels ^= 1 << label
            v = stacks[label].pop()
            decomposition_tree[u].append(v)
            u = v
    def dfs2(u, p):
        for v in graph[u]:
            if v != p: 
                dfs2(v, u)
                create_chain(dp1[v] & ~dp2[v], v)
                stacks[(dp2[v] & -dp2[v]).bit_length() - 1].append(v)
    root = 0
    dfs1(root, -1)
    dfs2(root, -1)
    decomposition_root = stacks[dp1[root].bit_length() - 1].pop()
    create_chain(dp1[root] & ~dp2[decomposition_root], decomposition_root)
    return decomposition_tree, decomposition_root

n = int(input())
graph = [[] for _ in range(n)]
for _ in range(n - 1):
    u,v = [int(x) - 1 for x in input().split()]
    graph[u].append(v)
    graph[v].append(u)
 
P = [-1] * n
P[0] = 0
bfs = [0]
for node in bfs:
    for nei in graph[node]:
        if P[nei] == -1:
            bfs.append(nei)
            P[nei] = node
 
decomposition_tree, decomposition_root = shallowest_edge_tree_decomposition(graph)

guess = decomposition_root
while True:
    print '?', guess + 1, P[guess] + 1
    ans = int(input()) - 1
 
    for cand in decomposition_tree[guess]:
        tmp = cand
        while tmp != 0 and tmp != guess:
            tmp = P[tmp]
        if tmp == guess == ans or (tmp != guess and guess != ans):
            guess = cand
            break
    else:
        print '!', ans + 1
        break