import sys
input = raw_input

def mapper(S):
    return [ord(c) - ord('a') for c in S]

def remapper(S):
    return ''.join(chr(c + ord('a')) for c in S)

def check(S, rem):
    T = []
    for c in rem:
        T += S
        S = [s for s in S if s != c]
    return T

t = int(input())
for _ in range(t):
    T = mapper(input())
    
    found = set()
    rem = []
    for c in reversed(T):
        if c not in found:
            found.add(c)
            rem.append(c)

    rem.reverse()

    rem2 = list(rem)
    
    n = 0
    while rem2:
        c = rem2.pop()
        n += T.count(c) // (len(rem2) + 1)

    if check(T[:n], rem) == T:
        print remapper(T[:n]), remapper(rem)
    else:
        print -1