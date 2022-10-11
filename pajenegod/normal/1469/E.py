import sys
range = xrange
input = raw_input

  
"""
Calculates the suffix array and LCP array in O(n) time
Example:
>>>> S = 'cabbage'
>>>> SA = SAIS([ord(c) for c in S])
>>>> LCP = KASAI(S, SA)
>>>> SA
[1, 4, 3, 2, 0, 6, 5]
>>>> LCP
[1, 0, 1, 0, 0, 0]
"""

def SAIS(A):
    """
    Calculates suffix array in O(len(A) + max(A))
    Input:
    Int list A with A[i] >= 0 for all i
    """
    n = len(A)
    buckets = [0] * (max(A) + 2)
    for a in A:
        buckets[a + 1] += 1
    for b in range(1, len(buckets)):
        buckets[b] += buckets[b - 1]
    isL = [1] * n
    for i in reversed(range(n - 1)):
        isL[i] = +(A[i] > A[i + 1]) if A[i] != A[i + 1] else isL[i + 1]

    def induced_sort(LMS):
        SA = [-1] * (n)
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
    rank = [0] * n
    for i in range(n):
        rank[SA[i]] = i
    LCP = [0] * (n - 1)
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

def solve(n,k,S):
    SA = SAIS(S)
    LCP = KASAI(S, SA)

    B = [1] * k
    checked = 0
    i = n - 1
    while True:
        while i and n - SA[i] < k:
            i -= 1
            checked = min(LCP[i], checked)
        
        if n - SA[i] < k:
            return B
        
        for ind in range(checked, k):
            if S[SA[i] + ind] != B[ind]:
                return B
        checked = k
        
        j = k - 1
        B[j] -= 1
        checked -= 1
        while j and B[j] < 0:
            B[j] = 1
            j -= 1
            B[j] -= 1
            checked -= 1

        if B[0] < 0:
            return

        while i and LCP[i - 1] >= k:
            i -= 1
        i -= 1
        if i < 0:
            return B
        checked = min(LCP[i], checked)
    return None

inp = sys.stdin.read().split(); ii = 0
out = []

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    k = int(inp[ii]); ii += 1
    S = inp[ii]; ii += 1
    S = [ord(c) - 48 for c in S]
    
    B = solve(n,k,S)
    if B is not None:
        print 'YES'
        print ''.join(str(1 - x) for x in B)
    else:
        print 'NO'