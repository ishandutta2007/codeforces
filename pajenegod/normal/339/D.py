# Not my code https://codeforces.com/blog/entry/107366
 
import sys
 
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
 
@bootstrap
def build(idx, i, j, flag):
    for _ in range(1):
        pass
    if i == j:
        tree[idx] = arr[i]
        yield 0
    mid = (i + j) // 2
    yield build(2 * idx + 1, i, mid, not flag)
    yield build(2 * idx + 2, mid + 1, j, not flag)
    if flag:
        tree[idx] = tree[2 * idx + 1] | tree[2 * idx + 2]
    else:
        tree[idx] = tree[2 * idx + 1] ^ tree[2 * idx + 2]
    # if idx == 1:
    #     print(tree[idx], tree[2*idx+1], tree[2*idx+2], tree[2*idx+1]^tree[2*idx+2],tree[2*idx+1]|tree[2*idx+2] )
    yield 0
 
@bootstrap
def update(idx, i, j, flag, index, val):
    for _ in range(1):
        pass
    if i == j == index:
        tree[idx] = val
        yield 0
    if i <= index <= j:
        mid = (i + j) // 2
        yield update(2 * idx + 1, i, mid, not flag, index, val)
        yield update(2 * idx + 2, mid + 1, j, not flag, index, val)
        if flag:
            tree[idx] = tree[2 * idx + 1] | tree[2 * idx + 2]
        else:
            tree[idx] = tree[2 * idx + 1] ^ tree[2 * idx + 2]
    yield 0
 
 
n, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
tree = [0] * (4 * len(arr))
build(0, 0, len(arr) - 1, n % 2 != 0)
for _ in range(k):
    index, val = map(int, sys.stdin.readline().split())
    update(0, 0, 2 ** n - 1, n % 2 != 0, index - 1, val)
    print(tree[0])