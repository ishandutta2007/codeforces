import sys
range = xrange
input = raw_input

B = []
for _ in range(10):
    row = [int(x) for x in input().split()]
    B.append(row)


DP = [0.0]*(100)
DP2 = [0.0]*(100)
for i in range(1, 100):
    ans = 0.0
    stand = 0
    for j in range(1,7):
        if i - j >= 0:
            ans += DP[i - j] /6.0
        else:
            stand += 1
    x = i % 10
    y = i // 10
    if y & 1:
        x = 9 - x

    h = B[y][x]
    if h:
        DP2[i] = 1 + ans
        
        y2 = y - h
        if y2 & 1:
            ind = y2 * 10 + (9 - x)
        else:
            ind = y2 * 10 + x
        DP[i] = min(1 + ans, DP2[ind])
    else:
        DP2[i] = DP[i] = (1 + ans)/(1 -  stand/6.0)
print DP[99]