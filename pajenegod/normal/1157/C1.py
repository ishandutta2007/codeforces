import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]




l = 0
r = n

stack = [-1]
move = []
while l<r:
    if A[l] == A[r-1]:
        break
    elif A[l]<A[r-1] and A[l]>stack[-1]:
        stack.append(A[l])
        l += 1
        move.append('L')
    elif A[r-1]>stack[-1]:
        stack.append(A[r-1])
        r -= 1
        move.append('R')
    else:
        break
stack1 = stack[:]
stack2 = stack[:]
move1 = move[:]
move2 = move[:]

i = l
while i<r and stack1[-1]<A[i]:
    stack1.append(A[i])
    i += 1
    move1.append('L')

i = r-1
while i>=l and stack2[-1]<A[i]:
    stack2.append(A[i])
    i -= 1
    move2.append('R')


if len(move1)>len(move2):
    print len(move1)
    print ''.join(move1)
else:
    print len(move2)
    print ''.join(move2)