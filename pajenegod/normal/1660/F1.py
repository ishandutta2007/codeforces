import sys

inp = sys.stdin.read().split(); ii = 0
t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    S = inp[ii]; ii += 1
    S = [+2*(c == '+')-1 for c in S]

    ans = 0
    for l in range(n):
        prev = 0
        count = 0
        countmm = 0

        for i in range(l, n):
            c = S[i]
            count += c
            
            if c == -1 and prev == -1:
                countmm += 1
                prev = 0
            else:
                prev = c
            
            x = countmm
            d,m = divmod(count, 3)
            ans += m == 0 and 0 <= -d <= x
            

    print(ans)