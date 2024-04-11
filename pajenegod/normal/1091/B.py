import sys
range = xrange
input = raw_input

# Will extremly quickly convert s into a list of integers.
# The format of the string is required to be integers (positive or negative)
# separated with a single character with ascii value <'-', so like a whitespace.
# It also handles the string ending with an additional character < '-', like a trailing newline.

s = sys.stdin.read()
inp = []
numb = 0
sign = 1
 
for i in range(len(s)):
    if s[i]>='0':
        numb = 10*numb + ord(s[i])-48
    else:
        if s[i]=='-':
            sign = -1
        else:
            inp.append(sign*numb)
            numb = 0
            sign = 1
if s[-1]>='0':
    inp.append(sign*numb)

ii = 0

n = inp[ii]
ii+=1

pairs = []
for _ in range(n):
    a,b = inp[ii],inp[ii+1]
    ii+=2
    pairs.append((a,b))
dx = []
for _ in range(n):
    a,b = inp[ii],inp[ii+1]
    ii+=2
    dx.append((a,b))

pair1 = max(pairs)
pair2 = min(dx)
pair3 = [pair1[i]+pair2[i] for i in range(2)]
print pair3[0],pair3[1]