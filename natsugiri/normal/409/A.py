import sys

A = sys.stdin.readline().rstrip()
B = sys.stdin.readline().rstrip()

cnt = 0
for i in range(0, len(A), 2):
    if ((A[i] == '[' and B[i] == '(') or
        (A[i] == '8' and B[i] == '[') or
        (A[i] == '(' and B[i] == '8')): cnt += 1
    if ((B[i] == '[' and A[i] == '(') or
        (B[i] == '8' and A[i] == '[') or
        (B[i] == '(' and A[i] == '8')): cnt -= 1

if cnt == 0: print('TIE')
if cnt > 0: print('TEAM 1 WINS')
if cnt < 0: print('TEAM 2 WINS')