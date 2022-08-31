#include <bits/stdc++.h>
#define maxn 1000005
#define pb push_back
#define iter multiset<int>::iterator
#define iter2 multiset<th>::iterator
using namespace std;
struct ST
{
	int l, r;
	ST *ch[2];
	int mn, lz;
}stp[maxn * 2], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r;
	a->mn = 0, a->lz = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	a->ch[0] = &stp[stcnt++];
	a->ch[1] = &stp[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid +1, r);
}
void pushlz(ST *a, int lz)
{
	a->lz += lz;
	a->mn += lz;
}
void upd(ST* a)
{
	a->mn = max(a->ch[0]->mn, a->ch[1]->mn);
}
void pushdown(ST *a)
{
	if(!a->lz) return;
	pushlz(a->ch[0], a->lz), 
	pushlz(a->ch[1], a->lz);
	a->lz = 0;
}
void push(ST *a, int l, int r, int ns)
{
//	cout<<"PUSH"<<l<<" "<<r<<endl;
	if(a->l == l && a->r == r)
	{
		pushlz(a, ns);
		return;
	}
	int mid = (a->l + a->r) >> 1;
	pushdown(a);
	if(r <= mid) push(a->ch[0], l, r, ns);
	else if(l > mid) push(a->ch[1], l, r, ns);
	else push(a->ch[0], l, mid, ns), 
		push(a->ch[1], mid +1, r, ns);
	upd(a);
}
struct th
{
	int pl, l, r, tp;
	bool operator < (const th &u)const
	{
		return pl < u.pl;
	}
}p[maxn];
int pls = 3000000;
int x[maxn], y[maxn];
int u[maxn];
map<int, int> s;
int main()
{
	int n, r;
	cin>>n>>r;
	root = &stp[stcnt++];
	
	
	int cnt = 0;
	int ncnt = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		u[cnt++] = x[i] - y[i] - r, u[cnt++] = x[i] - y[i] + r;
	}
	sort(u, u + cnt);
	int idcnt = 0; 
	for(int i = 0; i < cnt; i++)
		if(i == 0 || u[i] != u[i - 1])
			s[u[i]] = ++idcnt;
	bdtree(root, 1, idcnt);
	cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int ll = s[x[i] - y[i] - r], rr = s[x[i] - y[i] + r];
	//	cout<<i<<" "<<ll<<" "<<rr<<endl;
		p[cnt].pl = x[i] + y[i] - r, p[cnt].l = ll, p[cnt].r = rr, p[cnt].tp = 1;
		cnt++;
		p[cnt].pl = x[i] + y[i] + r + 1, p[cnt].l = ll, p[cnt].r = rr, p[cnt].tp = -1;
		cnt++;
	}
	sort(p, p + cnt);
	int ans = 0;
	for(int i = 0; i < cnt; )
	{
		int j = i;
		while(p[j].pl == p[i].pl && j < cnt)
		//	cout<<j<<" "<<p[j].l<<" "<<p[j].r<<" "<<idcnt<<endl,
			push(root, p[j].l, p[j].r, p[j].tp), 
			j++;
		ans = max(ans, root->mn);
		i = j;
	}
	cout<<ans<<endl;
	return 0;
}