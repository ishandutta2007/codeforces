def p(x):print(x,flush=True);a[int(input())-1]+=x
a=[*map(int,input().split())];print('First');p(10**9);p(max(a)*3-sum(a));p(max(a)-min(a)>>1)
# curious