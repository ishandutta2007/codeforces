#include <stdio.h>
#include <bits/stdc++.h>
#define ls p << 1
#define rs p << 1 | 1
#define mid ((l + r) >> 1)

using namespace std;

const int N = 2e5 + 10;

struct Node {int sum , lazy , len;} nod[N << 2];

void pushup(int p)
{
	nod[p].sum = nod[ls].sum + nod[rs].sum;
}

char a[N] , b[N];

void build(int p , int l , int r)
{
	nod[p].len = r - l + 1 , nod[p].lazy = -1;
	if(l == r)
		return (void) (nod[p].sum = a[l] - '0');
	build(ls , l , mid) , build(rs , mid + 1 , r);
	pushup(p);
}

void update(int p , int v)
{
	nod[p].sum = nod[p].len * v;
	nod[p].lazy = v;
}

void pushdown(int p)
{
	if(nod[p].lazy != -1)
	{
		update(ls , nod[p].lazy) , update(rs , nod[p].lazy);
		nod[p].lazy = -1;
	}
}

void add(int p , int l , int r , int ll , int rr , int v)
{
	if(ll <= l && r <= rr)
		return update(p , v);
	pushdown(p);
	if(ll <= mid)
		add(ls , l , mid , ll , rr , v);
	if(rr > mid)
		add(rs , mid + 1 , r , ll , rr , v);
	pushup(p); 
}

int query(int p , int l , int r , int ll , int rr)
{
	if(ll <= l && r <= rr)
		return nod[p].sum;
	pushdown(p);
	int ret = 0;
	if(ll <= mid)
		ret += query(ls , l , mid , ll , rr);
	if(rr > mid)
		ret += query(rs , mid + 1 , r , ll , rr);
	return ret;
}

void output(int p , int l , int r)
{
	if(l == r)
		return (void) (cout << nod[p].sum << " ");
	pushdown(p);
	output(ls , l , mid) , output(rs , mid + 1 , r);
}

int T;
int n , q;
int l[200010] , r[200010];

int main()
{
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d%d" , &n , &q);
		scanf("%s%s" , b + 1 , a + 1);
		for(int i = 1; i <= q; i++)
			cin >> l[i] >> r[i];
		build(1 , 1 , n);
		int flag = false;
		for(int i = q; i >= 1; i--)
		{
			int t = query(1 , 1 , n , l[i] , r[i]);
			int len = r[i] - l[i] + 1;
			if(len > t * 2)
				add(1 , 1 , n , l[i] , r[i] , 0);
			else if(len < 2 * t)
				add(1 , 1 , n , l[i] , r[i] , 1);
			else
			{
				flag = true;
				break;
			}
		}
		for(int i = 1; i <= n; i++)
			if(query(1 , 1 , n , i , i) != b[i] - '0')
				flag = true;
		if(flag == true)
			printf("NO\n");
		else
			printf("YES\n");
	} 
	return 0;
}