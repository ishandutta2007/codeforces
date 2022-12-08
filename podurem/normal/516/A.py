P = [0] * 16;
n = int(input())
s = input()

for i in s :
    if (i == '2') :
        P[2] += 1
    if (i == '3') :
        P[3] += 1
    if (i == '4') :
        P[3] += 1
        P[2] += 2
    if (i == '5') :
        P[5] += 1
    if (i == '6') :
        P[5] += 1
        P[3] += 1
    if (i == '7') :
        P[7] += 1
    if (i == '8') :
        P[2] += 3
        P[7] += 1
    if (i == '9') :
        P[7] += 1
        P[3] += 2
        P[2] += 1
for i in range(9, 0, -1) :
    for j in range(P[i]) :
        print(i, end = '')