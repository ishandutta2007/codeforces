# NOT MY CODE
# https://codeforces.com/contest/1334/submission/76180119
import sys, os
input = sys.stdin.buffer.read().split(b'\n')[::-1].pop
 
out = []
def print(x):
    out.append(str(x).encode('ascii'))
 
def next(st, n):
	if st==n-1:
		return 0
	return st+1
	
for t in range(int(input())):
    n = int(input())
    a = []
    b = []
    for i in range(n):
    	x, y = [int(j) for j in input().split()]
    	a.append(x)
    	b.append(y)
    if n==1:
    	print(a[0])
    	continue
    # print(m)
    st = min((b[i-1], a[i], i) for i in range(n))[2]
    num = 0
    bul = a[st]
    while(num<n-1):
    	nx = next(st, n)
    	# print(bul, st, nx)
    	bul += max(a[nx]-b[st], 0)
    	st = nx
    	num+=1
    ans = bul
    # print(bul)
    # print(m)
    st = min((a[i],b[i-1], i) for i in range(n))[2]
    num = 0
    bul = a[st]
    while(num<n-1):
    	nx = next(st, n)
    	# print(bul)
    	bul += max(a[nx]-b[st], 0)
    	st = nx
    	num+=1
    print(min(ans, bul))
os.write(1, b'\n'.join(out))