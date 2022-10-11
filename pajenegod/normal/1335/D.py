import sys
range = xrange
input = raw_input

ord0 = ord('0')
inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    A = []
    for _ in range(9):
        A.append([ord(c) - ord0 for c in inp[ii]]); ii += 1
    
    for y in range(0, 9, 3):
        for x in range(0, 9, 3):
            iii = y + (x//3)
            jjj = x + (y//3)
            A[iii][jjj] = (A[iii][jjj] % 9) + 1
    print '\n'.join(''.join(chr(c + ord0) for c in a) for a in A)