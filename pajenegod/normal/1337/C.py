# not my code 
# https://codeforces.com/contest/1337/submission/76945644
from sys import stdin
input = stdin.buffer.read().split(b'\n')[::-1].pop

### Pyrival bootstrap for unlimited requirsion
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
###

g = {}

@bootstrap
def obhod(k):
    for i in range(len(a[k])):
        a[a[k][i]].pop(a[a[k][i]].index(k))
        if len(a[a[k][i]]) > 0:
            yield obhod(a[k][i])
    yield

@bootstrap
def obhod2(k, f):
    c[k - 1] = f - (yield obhod3(k))
    for i in range(len(a[k])):
        yield obhod2(a[k][i], f + 1)
    yield

@bootstrap
def obhod3(k):
    x = 0
    x += len(a[k])
    for i in range(len(a[k])):
        if a[k][i] not in g:
            gg = yield obhod3(a[k][i])
            x += gg
            g[a[k][i]] = gg
        else:
            x += g[a[k][i]]
    yield x
 
n, k = map(int, input().split())
a = [0] * (n + 1)
for i in range(n + 1):
    a[i] = []
c = [0] * (n)
for i in range(n - 1):
    u, v = map(int, input().split())
    a[u].append(v)
    a[v].append(u)
if n != k:
    obhod(1)
    obhod2(1, 0)
    ans = 0
    c.sort(reverse=True)
    for i in range(k):
        ans += c[i]
    print(ans)
else:
    print(0)