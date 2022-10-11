import sys
range = xrange
input = raw_input

n = int(input())

V = [int(x) for x in input().split()]
P = [int(x) for x in input().split()]

A = [V,P]
for _ in range(n-2):
    A.append([int(x) for x in input().split()])

correct = [0]*5
for i in range(n):
    T = A[i]
    for j in range(5):
        if T[j]>=0:
            correct[j] += 1

def maxscore(correct, total):
    bound = [total//32 + 1, total//16 + 1, total//8 + 1, total//4 + 1, total//2 + 1, total+1]
    score = [3000, 2500, 2000, 1500, 1000, 500]
    for i in range(6):
        if correct<bound[i]:
            return score[i]

for cheaters in range(100000):
    s = 0
    for problem in range(5):
        if V[problem] == -1 and P[problem] == -1:
            continue

        if V[problem] == -1:
            ms = maxscore(correct[problem], n + cheaters)
            s -= ms - (ms//250)*P[problem]
        elif P[problem] == -1:
            ms = maxscore(correct[problem], n + cheaters)
            s += ms - (ms//250)*V[problem]
        elif V[problem] < P[problem]:
            ms = maxscore(correct[problem], n + cheaters)
            s += (ms//250)*(P[problem] - V[problem])
        else:
            ms = maxscore(correct[problem] + cheaters, n + cheaters)
            s += (ms//250)*(P[problem] - V[problem])
    if s>0:
        print cheaters
        break
else:
    print -1