import sys
range = xrange
input = raw_input

orda = ord('a')

t = int(input())
for _ in range(t):
    s = input()
    t = input()

    finder = [[] for _ in range(30)]
    for i in range(len(s)):
        finder[ord(s[i]) - orda].append(i)

    count = 1
    j = 0
    for i in range(len(t)):
        A = finder[ord(t[i]) - orda]
        if not A:
            print -1
            break

        a = 0
        b = len(A) - 1
        while a < b:
            c = a + b >> 1
            if A[c] < j:
                a = c + 1
            else:
                b = c
        if A[a] >= j:
            j = A[a] + 1
        else:
            j = A[0] + 1
            count += 1
    else:
        print count