import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    A = [ord(c) - ord('0') for c in input()]
    n = len(A)

    nesta = [n] * 10
    B = [list(nesta)]
    B.append(list(nesta))
    for i in reversed(range(n)):
        nesta[A[i]] = i
        B.append(list(nesta))
    B.reverse()
    
    counter = [0]*10
    for a in A:
        counter[a] += 1
    mini = n - max(counter)
    for i in range(100):
        b, a = divmod(i, 10)
        count = 0
        j = 0
        while True:
            j = B[j][a] + 1
            j = B[j][b] + 1
            if j > n:
                break
            count += 1
        mini = min(mini, n - 2 * count)
    print mini