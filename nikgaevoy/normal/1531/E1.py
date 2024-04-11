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
    log = []
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
    return None


def inv(a: list):
    b = [0 for i in range(len(a))]

    for i in range(len(a)):
        b[a[i]] = i + 1

    return b


def main():
    str = input()

    n = 0

    while True:
        a = sort_oracle(n, str)

        if a is not None:
            print(n)
            b = inv(a)
            print(*b, sep=' ')

            assert sort(b) == str

            return

        n += 1


main()