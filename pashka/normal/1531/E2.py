s = input()
c = 0


def mergeSort(l, r):
    global c
    if r - l <= 1:
        return True
    m = (l + r) >> 1
    if not mergeSort(l, m):
        return False
    if not mergeSort(m, r):
        return False
    i, j, k = l, m, l
    while i < m and j < r:
        if c == len(s):
            return False
        if s[c] == '0':
            c += 1
            b[k] = a[i]
            i += 1
        else:
            c += 1
            b[k] = a[j]
            j += 1
        k += 1
    while i < m:
        b[k] = a[i]
        i += 1
        k += 1
    while j < r:
        b[k] = a[j]
        j += 1
        k += 1
    for p in range(l, r):
        a[p] = b[p]
    return True


n = 1
while True:
    a = [i for i in range(n)]
    b = a[::]
    c = 0
    if mergeSort(0, n):
        if c == len(s):
            res = [0] * n
            for i in range(n):
                res[a[i]] = i + 1
            print(n)
            print(*res)
            break
    n += 1