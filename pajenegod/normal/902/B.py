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

# Not my code https://codeforces.com/blog/entry/91490?#comment-804801

an=0

@bootstrap
def dfs(node,p):
    global an
    if p==-1 or co[node]!=co[p]:
        an+=1
    for i in adj[node]:
        if i!=p:
            yield dfs(i,node )
    yield
n=int(input())
p=[int(x) for x in input().split()]
co=[int(x) for x in input().split() ]
dp=[1]*n
adj=[[]for i in range(n)]
for i in range(1,n):
    adj[i].append(p[i-1]-1)
    adj[p[i-1]-1].append(i)
dfs(0,-1)
print(an)