# Not my code
# https://codeforces.com/contest/1140/submission/51705578

import sys
range = xrange
raw_input = sys.stdin.read().split('\n')[::-1].pop

def bucketsort(order, seq):
    buckets = [0] * (max(seq) + 1)
    for x in seq:
        buckets[x] += 1
    for i in range(len(buckets) - 1):
        buckets[i + 1] += buckets[i]

    new_order = [-1] * len(seq)
    for i in reversed(order):
        x = seq[i]
        idx = buckets[x] = buckets[x] - 1
        new_order[idx] = i

    return new_order

def tuplesort(A):
    order = range(len(A))
    order = bucketsort(order, [a[1] for a in A])
    order = bucketsort(order, [a[0] for a in A])
    return [A[i] for i in order]

def main():
	n, m = map(int, raw_input().split())
	bit=[]
	bit2=[]
	a=[]
	b=[]
	c=[]
	d=[]
	bit.append(0)
	bit2.append(0)
	for i in range(0,n):
		x,y=map(int, raw_input().split())
		a.append((x,i))
		b.append((y,i))
		c.append(0)
		d.append(x)
		bit.append(0)
		bit2.append(0)
	a = tuplesort(a)
	b = tuplesort(b)
	for i in range(0,n):
		c[a[i][1]]=i
	ans=0
	for i in range(0,n):
		cur=b[n-i-1][1]
		beauty=b[n-i-1][0]
		ord=n-c[cur]
		while ord<=n:
			bit[ord]+=d[cur]
			bit2[ord]+=1
			ord+=ord&-ord
		sum=0
		cnt=0
		ptr=0
		for j in range(0,19):
			k=18-j
			newi=ptr|(1<<k)
			if newi<=n and cnt+bit2[newi]<=m:
				ptr=newi
				cnt+=bit2[ptr]
				sum+=bit[ptr]
		if ans<sum*beauty:
		    ans=sum*beauty
	print(ans)
if __name__ == '__main__':
    main()