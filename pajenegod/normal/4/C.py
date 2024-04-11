import sys
input = lambda: sys.stdin.readline().rstrip()
 
# not my code https://codeforces.com/blog/entry/104797
di, n, ans = {}, int(input()), []
li = [input() for e in range(n)]
for i in li:
    if i not in di:
        di[i] = 0
        ans.append("OK")
    else:
        di[i] += 1
        ans.append(i + str(di[i]))
print(*ans, sep='\n')