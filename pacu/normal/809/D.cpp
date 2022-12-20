#include <iostream>
#include <algorithm>
using namespace std;
#define NIL 400000
#define MAXN 400001

int l[MAXN],r[MAXN],p[MAXN],val[MAXN],inc[MAXN];
int nNodes;
int root;

void push(int x)
{
	val[x] += inc[x];
	if(l[x] != NIL) inc[l[x]] += inc[x];
	if(r[x] != NIL) inc[r[x]] += inc[x];
	inc[x] = 0;
}

void rot(int x)
{
	int y = p[x];
	push(y);
	push(x);
	if(x == l[y])
	{
		l[y] = r[x];
		if(r[x] != NIL) p[r[x]] = y;
		r[x] = y;
	}
	else
	{
		r[y] = l[x];
		if(l[x] != NIL) p[l[x]] = y;
		l[x] = y;
	}
	if(p[y] != NIL)
	{
		if(y==l[p[y]]) l[p[y]] = x;
		else r[p[y]] = x;
	}
	p[x] = p[y];
	p[y] = x;
}

void splay(int x)
{
	while(p[x] != NIL && p[p[x]] != NIL)
	{
		if((l[p[x]]==x) == (l[p[p[x]]]==p[x]))
			rot(p[x]);
		else
			rot(x);
		rot(x);
	}
	if(p[x] != NIL)
		rot(x);
}

void _invinsert(int y,int x)
{
	push(y);
	if(val[x] <= val[y])
	{
		if(l[y] != NIL)
			_invinsert(l[y],x);
		else
		{
			l[y] = x;
			p[x] = y;
		}
	}
	else
	{
		if(r[y] != NIL)
			_invinsert(r[y],x);
		else
		{
			r[y] = x;
			p[x] = y;
		}
	}
}

void insert(int v)
{
	int x = nNodes++;
	val[x] = v;
	p[x] = l[x] = r[x] = NIL;
	if(nNodes==1)
		root = x;
	else
	{
		_invinsert(root,x);
		splay(x);
		root = x;
	}
}

void rangeUpdate(int v,int dif) // change all values < v by dif
{
	int x = root;
	while(x != NIL)
	{
		push(x);
		if(val[x] < v)
		{
			val[x] += dif;
			if(l[x]!=NIL) inc[l[x]] += dif;
			x = r[x];
		}
		else
			x = l[x];
	}
}

int findFirst(int v)	//node with smallest value >= v
{
	int x = root;
	int y = NIL;
	while(x != NIL)
	{
		push(x);
		if(val[x] < v)
		{
			if(r[x]==NIL && y==NIL)
			{
				splay(x);
				root = x;
				return NIL;
			}
			x = r[x];
		}
		else
		{
			y = x;
			x = l[x];
		}
	}
	return y;
}

void erase(int x)
{
	splay(x);
	if(l[x] == NIL)
	{
		root = r[x];
		p[r[x]] = NIL;
		return;
	}
	if(r[x] == NIL)
	{
		root = l[x];
		p[l[x]] = NIL;
		return;
	}
	int y = l[x];
	p[y] = NIL;
	while(r[y] != NIL)
		y = r[y];
	splay(y);
	r[y] = r[x];
	p[r[x]] = y;
	root = y;
}

int getSize(int x)
{
	int sz = 1;
	if(l[x] != NIL) sz += getSize(l[x]);
	if(r[x] != NIL) sz += getSize(r[x]);
	return sz;
}

void traverse(int x)
{
	push(x);
	cout << val[x] << ' ';
	if(l[x] != NIL) traverse(l[x]);
	if(r[x] != NIL) traverse(r[x]);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	insert(0);
	int N,a,b;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> a >> b;
		//a = 1, b = 1000000000;
		int first = findFirst(b);
		if(first != NIL) erase(first);
		rangeUpdate(a,-1);
		rangeUpdate(b,1);
		insert(a);
	}
	cout << getSize(root)-1 << '\n';
}