import sys
input = raw_input
range = xrange

n = int(input())
H = [int(x) for x in input().split()]

if n==1:
    print(0)
    sys.exit()
        
H = H[1:]

n-=1

needed_marks = [-1]*n

needed_marks[0]=H[0]+1

for i in range(n):
    needed_marks[i] = max(needed_marks[i-1],H[i]+1)

for i in range(n-2,-1,-1):
    needed_marks[i] = max(needed_marks[i],needed_marks[i+1]-1)

marks = 1
summa = 0
for i in range(n):
    if marks<needed_marks[i]:
        marks+=1
    summa += marks-H[i]-1
print(summa)