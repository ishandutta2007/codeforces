import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

def SAIS(A):
    """
    Calculates suffix array in O(len(A) + max(A))
    Input:
    Int list A with A[i] >= 0 for all i
    """
    n = len(A)
    buckets = [0]*(max(A) + 2)
    for a in A:
        buckets[a + 1] += 1
    for b in range(1, len(buckets)):
        buckets[b] += buckets[b - 1]
    isL = [1]*n
    for i in reversed(range(n - 1)):
        isL[i] = +(A[i] > A[i + 1]) if A[i] != A[i + 1] else isL[i + 1]
    def induced_sort(LMS):
        SA = [-1]*(n)
        SA.append(n)
        endpoint = buckets[1:]
        for j in reversed(LMS):
            endpoint[A[j]] -= 1
            SA[endpoint[A[j]]] = j
        startpoint = buckets[:-1]
        for i in range(-1, n):
            j = SA[i] - 1
            if j >= 0 and isL[j]:
                SA[startpoint[A[j]]] = j
                startpoint[A[j]] += 1
        SA.pop()
        endpoint = buckets[1:]
        for i in reversed(range(n)):
            j = SA[i] - 1
            if j >= 0 and not isL[j]:
                endpoint[A[j]] -= 1
                SA[endpoint[A[j]]] = j
        return SA
    isLMS = [+(i and isL[i - 1] and not isL[i]) for i in range(n)]
    isLMS.append(1)
    LMS = [i for i in range(n) if isLMS[i]]
    if len(LMS) > 1:
        SA = induced_sort(LMS)
        LMS2 = [i for i in SA if isLMS[i]]
        prev = -1
        j = 0
        for i in LMS2:
            i1 = prev
            i2 = i
            while prev >= 0 and A[i1] == A[i2]:
                i1 += 1
                i2 += 1
                if isLMS[i1] or isLMS[i2]:
                    j -= isLMS[i1] and isLMS[i2]
                    break
            j += 1
            prev = i
            SA[i] = j
        LMS = [LMS[i] for i in SAIS([SA[i] for i in LMS])]
    return induced_sort(LMS)

def KASAI(A, SA):
    """
    Calculates LCP array in O(n) time 
    Input:
    String A and its suffix array SA
    """
    n = len(A)
    rank = [0]*n
    for i in range(n):
        rank[SA[i]] = i
    LCP = [0]*(n - 1)
    k = 0
    for i in range(n):
        SAind = rank[i]
        if SAind == n - 1:
            continue
        j = SA[SAind + 1]
        while i + k < n and A[i + k] == A[j + k]:
            k += 1
        LCP[SAind] = k
        k -= k > 0
    return LCP

class DisjointSetUnion:
    def __init__(self, n, A, B, C):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n
        self.A = A
        self.B = B
        self.C = C

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a
            ret = self.A[a] * self.B[a] * self.C[a] + self.A[b] * self.B[b] * self.C[b]

            self.num_sets -= 1
            self.parent[b] = a
            self.size[a] += self.size[b]
            self.A[a] += self.A[b]
            self.B[a] += self.B[b]
            self.C[a] += self.C[b]

            return self.A[a] * self.B[a] * self.C[a] - ret
        return 0

A = input()
B = input()
C = input()

M = min(len(A), len(B), len(C))
N = len(A) + len(B) + len(C) + 2

marker = [0] * (len(A) + 1) + [1] * (len(B) + 1) + [2] * len(C)
marks = []
for _ in range(3):
    marks.append([+(m == _) for m in marker])
dsu = DisjointSetUnion(N, *marks)

A = [ord(a) for a in A] + [1000] + [ord(b) for b in B] + [2000] + [ord(c) for c in C]
SA = SAIS(A)
LCP = KASAI(A, SA)

buckets = [[] for _ in range(N + 1)]
for i in range(N - 1):
    buckets[LCP[i]].append(i)

cur = 0
ans = [0]*(N + 1)
for l in reversed(range(1, N + 1)):
    for i in buckets[l]:
        cur += dsu.union(SA[i], SA[i + 1])
    ans[l] = cur
print ' '.join(str(x % MOD) for x in ans[1:M + 1])