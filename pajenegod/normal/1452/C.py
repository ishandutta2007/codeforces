import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

n = int(inp[ii]); ii += 1
ans = []

def solve(A):
    val = 0
    score = 0
    for a in A:
        if a:
            val += 1
        else:
            if val:
                score += 1
                val -= 1
    return score

for _ in range(n):
    S = inp[ii]; ii += 1
    
    score1 = solve([1 if c == '(' else 0 for c in S if c in '()'])
    score2 = solve([1 if c == '[' else 0 for c in S if c in '[]'])

    ans.append(score1 + score2)
print '\n'.join(str(x) for x in ans)