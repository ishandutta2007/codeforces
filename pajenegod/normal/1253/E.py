import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]


bucket = [-1]*(m + 1)
for _ in range(n):
    x,s = [int(x) for x in input().split()]
    x2 = max((x - s), 1)
    s2 = (x + s) - x2
    bucket[x2] = max(bucket[x2], s2)

X = []
S = []
for i in range(m + 1):
    if bucket[i] >= 0:
        X.append(i)
        S.append(bucket[i])


n = len(X)

DP = [[0]*(m + 1) for _ in range(n + 1)]
for i in reversed(range(n)):
    x = X[i]
    s = S[i]
    DPi = DP[i]
    DPip1 = DP[i + 1]
    for uncovered_x in range(1, m + 1):
        fin =  max(max(x - uncovered_x, m - (x + s)), 0)
        if i == n - 1:
            DPi[uncovered_x] =  fin
        else:
            back = max(0, x - uncovered_x)
            new_cover = (x + s) + back
            DPi[uncovered_x] = min(DPip1[uncovered_x],
                    back + (DPip1[new_cover + 1] if new_cover < m else 0), 
                    fin)
            #return min(f(uncovered_x, i + 1), back + f(new_cover + 1, i + 1))



def f(uncovered_x, i):
    x = X[i]
    s = S[i]

    if uncovered_x > m:
        return 0
    if i == n - 1:
        return max(max(x - uncovered_x, m - (x + s)), 0)
    else:
        back = max(0, x - uncovered_x)
        new_cover = (x + s) + back
        return min(f(uncovered_x, i + 1), back + f(new_cover + 1, i + 1))

print DP[0][1]