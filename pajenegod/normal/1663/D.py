import sys
S = input()
X = int(input())

bound = {'ABC':1999, 'ARC':2799, 'AGC':-1200}

def check(S):

    b = bound[S]
    if b < 0:
        return X >= -b
    else:
        return X <= b



if check(S):
    print('YES')
else:
    print('NO')