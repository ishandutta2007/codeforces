import sys


for es in sys.stdin.readlines()[2::2]:
    es = sorted([int(s) for s in es.split()])
    ans, cnt = 0, 0
    for e in es:
        cnt += 1
        if cnt >= e:
            ans, cnt = ans + 1, 0
    print(ans)