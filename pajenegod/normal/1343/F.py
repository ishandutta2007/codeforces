import sys
range = xrange
input = raw_input

def test(n, A, counter, isin, root):
    prio = [0]*n
    rem = [0]*(n - 1)
    used = [0]*n
    ans = []
    used[root] = 1
    for _ in range(n - 1):
        x = 0
        for i in range(1,n):
            if used[x] or (not used[i] and (counter[i] < counter[x] or (counter[i] == counter[x] and prio[i] > prio[x]))):
                x = i
        if counter[x] != 1 or any(prio[i] > prio[x] for i in range(n) if not used[i]) or prio[root] > prio[x]:
            return False, []

        used[x] = 1
        ans.append(x)
        for j in isin[x]:
            if not rem[j]:
                rem[j] = 1
                for y in A[j]:
                    counter[y] -= 1
                    prio[y] += 1
    if sum(counter) != 0 or prio[root] > prio[ans[-1]]:
        return False, []
    ans.append(root)
    return True, ans

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = []
    for _ in range(n - 1):
        k = inp[ii]; ii += 1
        A.append([x - 1 for x in inp[ii: ii + k]]); ii += k
    
    counter = [0]*n
    isin = [[] for _ in range(n)]
    for j in range(n - 1):
        a = A[j]
        for x in a:
            counter[x] += 1
            isin[x].append(j)
    for root in range(n):
        works, ans = test(n, A, list(counter), isin, root)
        if works:
            break
    print ' '.join(str(x + 1) for x in reversed(ans))