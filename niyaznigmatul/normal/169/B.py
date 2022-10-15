a = raw_input()
b = raw_input()
c = [0]*10
for i in range(len(b)):
    c[ord(b[i]) - ord('0')] += 1
d = ""
for i in range(len(a)):
    for j in range(9, ord(a[i]) - ord('0'), -1):
        if c[j] > 0:
            c[j] -= 1
            d += (chr(j + ord('0')))
            break
    if len(d) == i:
        d += (a[i])
print d