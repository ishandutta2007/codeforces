import sys
import string
range = xrange
input = raw_input

alph = string.ascii_lowercase

n = int(input())
S = sys.stdin.read().split()

besta = 0
for a in alph:
    cur = 0
    for s in S:
        if all(c==a for c in s):
            cur = cur + len(s)*(cur+1)
        else:
            lcount = 0
            while lcount<len(s) and s[lcount]==a:lcount += 1
            rcount = 0
            while rcount<len(s) and s[len(s)-rcount-1]==a:rcount += 1


            i = 0
            longest = 0
            for j in range(len(s)):
                if s[j]==a:
                    longest = max(longest,j-i+1)
                else:
                    i=j+1
            if cur>0:
                cur = max(1+lcount+rcount,longest)
            else:
                cur = longest
    besta = max(besta,cur)
print besta