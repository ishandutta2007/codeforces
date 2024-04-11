# Not my code: https://codeforces.com/gym/329079/submission/116929037
 
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
 
 
from collections import defaultdict
import sys
n = int(input())
children = defaultdict(list)
coloursneeded = defaultdict(int)
for node, parent in enumerate([int(x) for x in input().split()], start = 2):
    children[parent].append(node)
 
@bootstrap
def needed(node):
    if node not in children.keys():
        coloursneeded[node] = 1
        yield 1
    val = 0
    for a in children[node]:
        val += (yield needed(a))
    coloursneeded[node] = val
    yield val
 
needed(1)
print(*sorted(coloursneeded.values()), sep= " ")