#include <bits/stdc++.h>

const int maxn = 100111;
const int magic = 1000;

int n, q, a[maxn];

inline bool equal(int *a, int *b, int n) { return (memcmp(a, b, n << 2) == 0); }

struct Block
{
	int l, r, openTot, closeTot, open[magic + 10], close[magic + 10];
	bool good;
	void construct()
	{
		openTot = closeTot = 0;
		good = 1;
		for(int i=l; i<=r; i++)
		{
			if(a[i] > 0) open[openTot++] = a[i];
			else if(openTot && open[openTot-1] + a[i])
			{
				good = 0;
				return;
			}
			else if(openTot == 0) close[closeTot++] = -a[i];
			else openTot--;
		}
		std::reverse(close, close + closeTot);
	}
};
Block b[maxn / magic + 10];
int btot, bid[maxn];

bool query(int l, int r)
{
	static int stk[maxn], top;
	
	top = 0;
	if(bid[l] == bid[r])
	{
		for(int i=l; i<=r; i++)
		{
			if(a[i] > 0) stk[top++] = a[i];
			else if(top && stk[top-1] == -a[i]) top--;
			else return false;
		}
		return (top == 0);
	}
	int id = bid[l];
	if(b[id].l != l)
	{
		for(int i=l; i<=b[id].r; i++)
		{
			if(a[i] > 0) stk[top++] = a[i];
			else if(top && stk[top-1] == -a[i]) top--;
			else return false;
		}
		id++;
	}
	while(b[id].r <= r)
	{
		if(!b[id].good) return false;
		if(b[id].closeTot && (b[id].closeTot > top || !equal(b[id].close, stk + (top - b[id].closeTot), b[id].closeTot))) return false;
		top -= b[id].closeTot;
		memcpy(stk + top, b[id].open, b[id].openTot << 2);
		top += b[id].openTot;
		id++;
	}
	for(int i=b[id].l; i<=r; i++)
	{
		if(a[i] > 0) stk[top++] = a[i];
		else if(top && stk[top-1] == -a[i]) top--;
		else return false;
	}
	return (top == 0);
}

int main()
{
	scanf("%d%*d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	scanf("%d", &q);
	
	for(int i=1; i<=n; i+=magic)
	{
		btot++;
		b[btot].l = i;
		b[btot].r = std::min(n, i + magic - 1);
		for(int j=b[btot].l; j<=b[btot].r; j++) bid[j] = btot;
		b[btot].construct();
	}
	b[btot+1].l = b[btot+1].r = n+1;
	
	for(int i=1, op, x, y; i<=q; i++)
	{
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1)
		{
			a[x] = y;
			b[bid[x]].construct();
		}
		else puts(query(x, y) ? "Yes" : "No");
	}
	return 0;
}