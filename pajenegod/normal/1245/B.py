import sys
range = xrange
input = raw_input

t = int(input())

out = []

mapper = {'R':0, 'P':1, 'S':2}
remapper = 'RPS'

for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    S = [mapper[c] for c in input()]

    wins = 0
    choice = []
    for i in range(n):
        c = S[i]
        counter = (c + 1)%3
        if A[counter]:
            A[counter] -= 1
            choice.append(counter)
            wins += 1
        else:
            choice.append(-1)

    j = 0
    for i in range(n):
        if choice[i] == -1:
            while A[j] == 0:
                j += 1
            choice[i] = j
            A[j] -= 1

    if 2*wins >= n:
        print 'YES'
        print ''.join(remapper[c] for c in choice)
    else:
        print 'NO'