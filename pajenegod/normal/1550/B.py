import sys
input = raw_input

t = int(input())
for _ in range(t):
    n,a,b = [int(x) for x in input().split()]
    S = input()
    
    counter = []
    i = 0
    while i < n:
        prev = S[i]
        j = i
        while j < n and S[j] == prev:
            j += 1
        counter.append(j - i)
        i = j
    counter1 = counter[::2]
    counter2 = counter[1::2]

    if b >= 0:
        print (a + b) * n
    else:
        print a * n + b * (1 + len(counter2))