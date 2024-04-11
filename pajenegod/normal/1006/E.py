# Not my code
# https://codeforces.com/contest/1006/submission/118525767
 
# https://github.com/cheran-senthil/PyRival/blob/master/pyrival/misc/bootstrap.py
from types import GeneratorType
 
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
 
    return wrappedfunc
 
 
import sys,os,io
from sys import stdin
from collections import defaultdict
 
def ii():
    return int(input())
def li():
    return list(map(int,input().split()))
 
 
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r") ; sys.stdout = open("output.txt","w") 
else:
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
 
cnt = 1
d = defaultdict(lambda:0)
travesal = []
subtreesize = defaultdict(lambda:0)
 
@bootstrap
def dfs(node,parent):
    global adj,cnt
    travesal.append(node)
    ans = 1
    for child in adj[node]:
        if child==parent:
            continue
        d[child]=cnt
        cnt+=1
        ans+=(yield dfs(child,node))
    subtreesize[node]=ans
    yield ans
 
n,q = li()
p = li()
adj = [[] for i in range(200002)]
for i in range(len(p)):
    adj[i+1].append(p[i]-1)
    # print(p[i]-1)
    adj[p[i]-1].append(i+1)
dfs(0,-1)
for i in range(len(travesal)):
    travesal[i]+=1
for i in range(q):
    u,k = li()
    u-=1
    dis = d[u]
    x = dis+k-1
    # print("x",x)
    if x>=len(travesal) or subtreesize[u]<k:
        print(-1)
    else:
        print(travesal[x])