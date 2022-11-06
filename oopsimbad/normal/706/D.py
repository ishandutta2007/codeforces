
_0 = [-1]
_1 = [-1]
sz = [0]

def add_node():
    ind = len(sz)
    _0.append(-1)
    _1.append(-1)
    sz.append(0)
    return ind

def upd(node, x, d, change):
    sz[node] += change
    if(d == -1):
        return
    
    if x & (1 << d):
        if _1[node] == -1:
            _1[node] = add_node()
        upd(_1[node], x, d-1, change)
    else:
        if _0[node] == -1:
            _0[node] = add_node()
        upd(_0[node], x, d-1, change)

def query(node, x, d):
    if (d == -1):
        return 0

    if x & (1 << d):
        if _0[node] == -1 or sz[_0[node]] == 0:
            return query(_1[node], x, d-1)
        else:
            return query(_0[node], x, d-1) + (1 << d)
    else:
        if _1[node] == -1 or sz[_1[node]] == 0:
            return query(_0[node], x, d-1)
        else:
            return query(_1[node], x, d-1) + (1 << d)

q = int(input())
upd(0, 0, 30, 1)
for _ in range(q):
    op, x = input().split()
    x = int(x)

    if op == '+':
        upd(0, x, 30, 1)
    elif op == '-':
        upd(0, x, 30, -1)
    else:
        print(query(0, x, 30), flush=False)