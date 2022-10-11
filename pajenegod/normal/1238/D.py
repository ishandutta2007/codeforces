import sys
range = xrange
input = raw_input

n = int(input())

ordA = ord('A')
S = [ord(c) - ordA for c in input()]

fore = [n]*26
nesta = []
for i in reversed(range(n)):
    nesta.append(list(fore))
    fore[S[i]] = i
nesta.reverse()


#innan = [-1]*26
#prev = []
#for i in range(n):
#    prev.append(list(innan))
#    innan[S[i]] = i

count = [0]*26
counter = [list(count)]
for i in range(n):
    count[S[i]] += 1
    counter.append(list(count))

ans = 0
for i in range(n):
    
    j = nesta[i][S[i]]

    c1 = counter[i]
    c2 = counter[j]

    count = [c2[c] - c1[c] for c in range(26)]

    while j < n:
        # handle transition to j
        count[S[j]] += 1

        for c in range(26):
            if count[c] == 1:
                ci = nesta[i][c]
                if ci == j:
                    # substring currently bad
                    j += 1
                    break
                elif S[ci - 1] != S[ci + 1]:
                    # substring currently bad
                    j2 = nesta[ci][c]
                    
                    c2 = counter[j2]
                    count = [c2[c] - c1[c] for c in range(26)]
                    j = j2
                    break
        else:
            # substring currently good
            c = 0
            while c < 26 and count[c] != 0:
                c += 1

            if c == 26:
                ans += n - j
                j = n
            else:
                ans += nesta[j][c] - j
                j = nesta[j][c]
            continue
print ans