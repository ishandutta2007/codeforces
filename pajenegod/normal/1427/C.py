import sys
range = xrange
input = raw_input
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
r = inp[ii]; ii += 1
n = inp[ii]; ii += 1
 
T = inp[ii + 0: ii + 3 * n: 3]
X = inp[ii + 1: ii + 3 * n: 3]
Y = inp[ii + 2: ii + 3 * n: 3]

T.append(0)
X.append(1)
Y.append(1)

dic = [[] for _ in range(n + 1)]
dic[0].append(n)
 
m = 0
for i in range(n):
    x = X[i]
    y = Y[i]
    t = T[i]

    for last in reversed(range(m + 1)):
        for j in dic[last]:
            if abs(x - X[j]) + abs(y - Y[j]) <= t - T[j]:
                dic[last + 1].append(i)
                m += last == m
                break
        else:
            continue
        break

print m