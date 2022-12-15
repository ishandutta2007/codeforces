n,m=map(int,raw_input().split())
for i in range(100000):
    if i==i/m+n:
        print i
        break