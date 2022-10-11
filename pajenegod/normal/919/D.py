# NOT MY CODE
# https://codeforces.com/contest/919/submission/80857731
 
from types import GeneratorType
 
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        to = f(*args, **kwargs)
        if stack:
            return to
        else:
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        return to
                    to = stack[-1].send(to)
    return wrappedfunc
 
import sys
input=sys.stdin.readline
from collections import defaultdict as dd
'''
def iscyclic(g):
    for i in range(1,n+1):
        if(
'''
n,m=map(int,input().split())
s=input()
d=dd(list)
lol=0
for i in range(m):
    u,v=map(int,input().split())
    if(u==v):
        lol=1
        print(-1)
        exit()
    d[u].append(v)
'''
if(iscyclic(d)):
    lol=1
    print(-1)
    exit()
'''
vis=[0]*(n+1)
rvis=[0]*(n+1)
cou=[0]
dp=[dd(int) for i in range(n+1)]
mx=[0]
h=[0]
#print(d)
@bootstrap
def dfs(u):
    if(h[0]==1):
        yield
    vis[u]=1
    rvis[u]=1
    for i in d[u]:
        if(h[0]==1):
            yield
        if(vis[i]==0):
            yield dfs(i)
            if(h[0]==1):
                yield            
        elif(rvis[i]==True):
            h[0]=1
            yield
    rvis[u]=0
    if(h[0]==1):
        yield
    for i in d[u]:
        for j in dp[i]:
            dp[u][j]=max(dp[u][j],dp[i][j])
            mx[0]=max(mx[0],dp[u][j])
    dp[u][s[u-1]]+=1
    #print(u,dp[u])
    mx[0]=max(mx[0],dp[u][s[u-1]])
    yield
#print(dp)
for i in range(1,n+1):
    if(vis[i]==0):
        cou=[0]
        dfs(i)
if(h[0]):
    print(-1)
else:
    print(mx[0])