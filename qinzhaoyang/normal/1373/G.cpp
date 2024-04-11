#include <iostream>
#include <cmath> 
#include <set>
#include <cstdio>

using namespace std;

const int N = 2e5 + 10;

int n , k , m;
int w[N << 3] , lazy[N << 3];
int cnt[N << 1];

void update(int p)
{
	w[p] = max(w[p << 1] , w[p << 1 | 1]);
}

void build(int p , int l , int r)
{
	if(l == r)
	{
		w[p] = l - 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1 , l , mid);
	build(p << 1 | 1 , mid + 1 , r);
	update(p);
}

int pushdown(int p)
{
	if(lazy[p])
	{
		w[p << 1] += lazy[p];
		w[p << 1 | 1] += lazy[p];
		lazy[p << 1] += lazy[p];
		lazy[p << 1 | 1] += lazy[p];
		lazy[p] = 0;
	}
}

void add(int p , int l , int r , int ll , int rr , int x)
{
	if(ll <= l && r <= rr)
	{
		w[p] += x;
		lazy[p] += x;
		return;
	}
	pushdown(p);
	int mid = (l + r) >> 1;
	if(ll <= mid)
		add(p << 1 , l , mid , ll , rr , x);
	if(rr > mid)
		add(p << 1 | 1 , mid + 1 , r , ll , rr , x);
	update(p);
} 

int query(int p , int l , int r , int ll , int rr)
{
	if(ll <= l && r <= rr)
		return w[p];
	pushdown(p);
	int mid = (l + r) >> 1 , ret = 0;
	if(ll <= mid)
		ret = max(ret , query(p << 1 , l , mid , ll , rr));
	if(rr > mid)
		ret = max(ret , query(p << 1 | 1 , mid + 1 , r , ll , rr));
	return ret;
}

set <pair<int , int> > a;
set <int> b; 

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k >> m;
	build(1 , 1 , 2 * n);
	while(m--)
	{
		int x , y;
		cin >> x >> y;
		int pos = y + (int)abs(x - k);
		pair <int , int> P = make_pair(x , y);
		if(a.count(P))
		{
			--cnt[pos];
			if(cnt[pos] == 0)
				b.erase(pos);
			add(1 , 1 , 2 * n , 1 , pos , -1);
			a.erase(P);
		}
		else
		{
			++cnt[pos];
			if(cnt[pos] == 1)
				b.insert(pos);
			add(1 , 1 , 2 * n , 1 , pos , 1);
			a.insert(P);
		}
		if(b.empty())
			cout << 0 << endl;
		else
			cout << max(0 , query(1 , 1 , 2 * n , 1 , *b.rbegin()) - n) << endl;
	}
	return 0;
}