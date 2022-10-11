# testing https://codeforces.com/contest/1263/submission/66044015
 
def dfs(n):
    global visited
    global chars
    visited[n] = True
    adj = list(set(chars.get(n, [])))
    for node in adj:
        if not visited[node]:
            dfs(node)
 
import sys
inp = sys.stdin.buffer.read().split(); ii = 0
 
n = int(inp[ii]); ii += 1
chars = {}
visited = {}
while n:
    n -= 1
    s = list(set(inp[ii])); ii += 1
    flag = 0
    if not s[0] in chars:
        chars[s[0]] = []
        visited[s[0]] = False
    for i in range(1, len(s)):
        chars[s[0]].append(s[i])
        if not s[i] in chars:
            chars[s[i]] = [s[0]]
        else:
            chars[s[i]].append(s[0])
        visited[s[i]] = False
 
 
ans = 0
for k, v in chars.items():
    if not visited[k]:
        dfs(k)
        ans += 1
print(ans)