import sys
 
S2 = 'Timur'
 
t = int(input())
for _ in range(t):
    n = int(input())
    S = input()
 
    if sorted(S) == sorted(S2):
        print('YES')
    else:
        print('NO')