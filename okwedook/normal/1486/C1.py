from sys import stdout

def ask(l, r):
    if l == r:
        return -1
    print('?', l, r)
    stdout.flush()
    return int(input())

l = 1
r = int(input()) + 1
while r - l > 1:
    mid = (r + l) // 2
    was = ask(l, r - 1)
    if was < mid:
        if ask(l, mid - 1) == was:
            r = mid
        else:
            l = mid
    else:
        if ask(mid, r - 1) == was:
            l = mid
        else:
            r = mid
print('!', l)
stdout.flush()