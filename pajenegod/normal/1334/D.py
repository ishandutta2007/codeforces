import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,l,r = [int(x) for x in input().split()]
    l -= 1

    ind = l
    val = 1
    ans = []
   
    while len(ans) < r - l:
        while ind >= 2 * (n - val) and val < n:
            ind -= 2 * (n - val)
            val += 1
        if val == n:
            ans += [1]
        else:
            ans += [val if i & 1 == 0 else val + (i + 1)//2 for i in range(2 * (n - val))][ind:]
        val += 1
        ind = 0
    print ' '.join(str(x) for x in ans[:r-l])