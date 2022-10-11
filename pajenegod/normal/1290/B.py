import sys
range = xrange
input = raw_input

orda = ord('a')

s = input()
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

bucket = [0]*30
cumsum = [list(bucket)]
for i in range(len(s)):
    bucket[ord(s[i]) - orda] += 1
    cumsum.append(list(bucket))

# A[l] != A[r - 1] -> True
# A[l] == A[r]

out = []
q = inp[ii]; ii += 1
for _ in range(q):
    l = inp[ii] - 1; ii += 1
    r = inp[ii]; ii += 1

    if r - l == 1:
        out.append(1)
        continue
    if s[l] != s[r - 1]:
        out.append(1)
        continue

    lbucket = cumsum[l]
    rbucket = cumsum[r]

    count = 0
    for i in range(30):
        if rbucket[i] - lbucket[i]:
            count += 1
    if count > 2:
        out.append(1)
    else:
        out.append(0)
print '\n'.join('Yes' if x else 'No' for x in out)