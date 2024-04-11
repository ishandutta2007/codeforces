from sys import stdout


def req(l, r, k=0):
    print('?', l, r)
    v = [''.join(sorted(input())) for i in range((r - l + 1) * (r - l + 2) // 2)]
    stdout.flush()
    return v


def compute(v):
    bukvi = [[0] * (n + 2) for _ in range(26)]
    for el in v:
        cur = len(el)
        for e in el:
            bukvi[ord(e) - ord('a')][cur] += 1
    return bukvi


def compute2(bukvi):
    bukvis = [[] for _ in range(26)]
    for i in range(26):
        prev = bukvi[i][1]
        for j in range(1, n // 2 + n % 2 + 1):
            while bukvi[i][j] != prev:
                bukvis[i].append(j)
                prev -= 1
    return bukvis


def main():
    va = req(1, n)
    # va2 = req(1, n // 2)
    # va3 = req(n - n // 2 + 1, n)
    # bukvi = compute(va)
    # bukvi2 = compute(va2)
    # bukvi3 = compute(va3)
    if n == 1:
        print('!', va[0][0])
        return
    va2 = req(2, n)
    for i in va2:
        va.remove(i)
    va.sort(key=len)
    print('!', va[0], end='')
    for i in range(1, len(va)):
        for j in range(26):
            if va[i].count(chr(ord('a') + j)) != va[i - 1].count(chr(ord('a') + j)):
                print(chr(ord('a') + j), end='')
    print()


n = int(input())
main()