from sys import stdout


class String2:
    def __init__(self, s, b=None):
        if b is not None:
            self.b = b
            return
        self.b = [0] * 26
        for i in s:
            self.b[ord(i) - ord('a')] += 1

    def __add__(self, other):
        b = self.b.copy()
        for i in range(26):
            b[i] += other.b[i]
        return String2('', b)

    def __sub__(self, other):
        b = self.b.copy()
        for i in range(26):
            b[i] -= other.b[i]
        return b

    def __mul__(self, other):
        ans = String2('', self.b)
        for i in range(26):
            ans.b[i] *= other
        return ans



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
    bukvis = [set() for i in range(n + 2)]
    for i in range(26):
        prev = bukvi[i][1]
        for j in range(1, n // 2 + n % 2 + 1):
            while bukvi[i][j] != prev:
                bukvis[j].add(chr(ord('a') + i))
                prev += 1
    return bukvis


def solve(va, va2):
    for i in va2:
        va.remove(i)
    va.sort(key=len)
    s = va[0]
    for i in range(1, len(va)):
        for j in range(26):
            if va[i].count(chr(ord('a') + j)) != va[i - 1].count(chr(ord('a') + j)):
                s += chr(ord('a') + j)
    return s


def check(v, s, s2, f):
    s3 = String2(v[0])
    for i in range(1, len(v)):
        s3 = s3 + String2(v[i])
    le = len(v[0])
    cur = String2('', String2('', f - String2(s)) - String2(s2)) * le
    for i in range(le - 2):
        cur = cur + (String2(s[i]) * (i + 1)) + (String2(s2[-i-1]) * (i + 1))
    cur = cur + (String2(s[le - 2]) * (le - 1)) + (String2(s[le - 1:]) * le)
    e = cur - s3
    for i in range(26):
        if e[i]:
            return chr(ord('a') + i)


def main():
    if n == 1:
        va = req(1, 1)
        print('!', va[0])
        return
    elif n == 2:
        va2 = req(1, 1)
        va3 = req(2, 2)
        print('!', va2[0] + va3[0])
        return
    elif n == 3:
        va = req(1, 1)
        va2 = req(2, 2)
        va3 = req(3, 3)
        print('!', va[0] + va2[0] + va3[0])
        return
    va = req(1, n)
    va2 = req(1, max(n // 2 + n % 2, 2))
    va3 = req(2, max(n // 2 + n % 2, 2))
    # bukvi2 = compute(va2)
    # bukvi3 = compute(va3)
    ma = [[] for i in range(n * 2)]
    for i in va:
        ma[len(i)].append(i)
    a = String2(''.join(ma[1]))
    s = solve(va2, va3)
    s2 = ''
    for i in range(2, n // 2 + 1):
        s2 = check(ma[i], s, s2, a) + s2
    se = String2('', a - String2(s)) - String2(s2)
    for i in range(len(se)):
        if se[i]:
            s += chr(ord('a') + i)
            break
    print('!', s + s2)


n = int(input())
main()