import sys
range = xrange
input = raw_input

n = int(input())

s = sys.stdin.read().split('\n')
s = [c for c in s if c]

assert(len(s)==n)

A = []
B = []
typec = 0

for par in s:
    stack = []
    for c in par:
        if stack and stack[-1]=='(' and c==')':
            stack.pop()
        else:
            stack.append(c)
    a = stack.count('(')
    b = stack.count(')')

    if a>0 and b>0:
        continue
    elif a>0:
        A.append(a)
    elif b>0:
        B.append(b)
    else:
        typec+=1

A.sort()
B.sort()

pairs = typec//2
while A and B:
    if A[-1]==B[-1]:
        A.pop()
        B.pop()
        pairs += 1
    elif A[-1]<B[-1]:
        B.pop()
    else:
        A.pop()


print pairs