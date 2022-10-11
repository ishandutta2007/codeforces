import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    x = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    not_good = n
    is_good = [0] * n
    def check(i):
        if 0 <= i < n:
            global not_good
            if not is_good[i] and (i == 0 or A[i - 1] <= A[i]) and (i == n - 1 or A[i] <= A[i + 1]):
                is_good[i] = 1
                not_good -= 1
        

    for i in range(n): 
        check(i)

    count = 0
    for i in range(n):
        if not_good and A[i] > x:
            A[i], x = x, A[i]
            check(i - 1)
            check(i)
            check(i + 1)
            count += 1

    print -1 if not_good else count