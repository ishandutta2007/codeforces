import sys
range = xrange
input = raw_input

n = int(input())

A = [int(x) for x in input().split()]

stack_h = []
stack_count = []

for a in A:
    while stack_h and stack_h[-1] < a:
        stack_h.pop()
        if stack_count.pop() & 1:
            print 'NO'
            sys.exit()

    if stack_h and stack_h[-1] == a:
        stack_count[-1] += 1
    else:
        stack_h.append(a)
        stack_count.append(1)

while len(stack_count) > 1:
    if stack_count.pop()&1:
        print 'NO'
        sys.exit()

print 'YES'