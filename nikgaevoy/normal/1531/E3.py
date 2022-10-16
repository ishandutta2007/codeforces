import cProfile
import math
import random


def sort(a):
    n = len(a)
    b = [0 for i in range(n)]
    log = []

    def mergeSort(l, r):
        if r - l <= 1:
            return
        m = (l + r) >> 1
        mergeSort(l, m)
        mergeSort(m, r)
        i, j, k = l, m, l
        while i < m and j < r:
            if a[i] < a[j]:
                log.append('0')
                b[k] = a[i]
                i += 1
            else:
                log.append('1')
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

    mergeSort(0, n)
    return "".join(log)


def sort_oracle(n, com):
    a = [i for i in range(n)]
    b = [0 for i in range(n)]
    ind, sz = 0, len(com)
    bad = False

    def mergeSort(l, r):
        nonlocal ind, bad
        if r - l <= 1:
            return
        m = (l + r) >> 1
        mergeSort(l, m)
        mergeSort(m, r)
        i, j, k = l, m, l
        while i < m and j < r:
            if ind == sz:
                bad = True
                return
            if com[ind] == '0':
                b[k] = a[i]
                i += 1
            else:
                assert com[ind] == '1';
                b[k] = a[j]
                j += 1
            k += 1
            ind += 1
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

    mergeSort(0, n)

    if not bad and ind == sz:
        return a
    return bad


def inv(a: list):
    b = [0 for i in range(len(a))]

    for i in range(len(a)):
        b[a[i]] = i + 1

    return b


def solve(com):
    l, r = 0, int(2e5)

    while True:
        t = (l + r) // 2
        a = sort_oracle(t, com)

        if type(a) is list:
            print(t)
            b = inv(a)
            print(*b, sep=' ')

            # assert sort(b) == com

            return

        if a:
            r = t
        else:
            l = t


def main():
    solve(input())


def check():
    perm = [i for i in range(int(1e5))]

    random.shuffle(perm)

    solve(sort(perm))


# cProfile.run("check()")
main()