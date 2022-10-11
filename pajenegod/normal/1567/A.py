import sys
input = raw_input

mapper = {'L':'L', 'R':'R', 'U':'D', 'D':'U'}

t = int(input())
for _ in range(t):
    n = int(input())
    S = input()
    print ''.join(mapper[c] for c in S)