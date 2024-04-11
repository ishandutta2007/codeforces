import sys
range = xrange
input = raw_input

orda = ord('a')
S = [ord(c) - orda for c in input()]
n = len(S)

count1 = [0]*30
count2 = [0]*(30*30)

for i in range(n):
    c = S[i]
    for j in range(30):
        count2[j + 30*c] += count1[j]
    count1[c] += 1

print max(max(count2),max(count1))