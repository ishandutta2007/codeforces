import sys
range = xrange
input = raw_input

n = int(input())
X = [int(x) for x in input().split()]

Y = [0]*n
for x in X:
    Y[x - 1] = 1

finalY = [0]*(n + 2)
for i in range(n):
    if Y[i]:
        if finalY[i - 1] or finalY[i]:
            pass
        else:
            finalY[i + 1] = 1

mini = sum(finalY)

Y = [0]*n
for x in X:
    Y[x - 1] += 1
    
finalY = [0]*(n + 2)
for i in range(n):
    if Y[i]:
        if finalY[i - 1] == 0:
            finalY[i - 1] += 1
            Y[i] -= 1
    if Y[i]:
        if finalY[i] == 0:
            finalY[i] += 1
            Y[i] -= 1
    if Y[i]:
        if finalY[i + 1] == 0:
            finalY[i + 1] += 1
            Y[i] -= 1

maxi = sum(+(x>0) for x in finalY)

print mini,maxi