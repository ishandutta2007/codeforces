#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mitte (lewy+prawy)/2
#define debug printf 
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 5e5+100;

int ojce[N], Cons[N], moc[N];
vector <int> ev;
int krol (int a)
{
	if (ojce[a]==0) return a;
	return krol(ojce[a]);
}
bool unia (int a, int b)
{
	int ka = krol(a), kb = krol(b);
	if (ka==kb) 
	{
		ev.pb(-1);
		return false;
	}
	
	if (moc[kb] > moc[ka]) swap(ka, kb);
	
	ev.pb(kb);
	moc[ka] += moc[kb];
	ojce[kb] = ka;
	return true;
}

void rev ()
{
	int kb = ev.back();
	ev.pop_back();
	if (kb==-1) return;
	int ka = ojce[kb];
	ojce[kb] = 0;
	moc[ka] -= moc[kb];
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	int n, m, q;
	scanf ("%d %d", &n, &m);
	rep(i,1,n+1) moc[i] = 1;
	
	vector <pair <int, pair <int, int> > > E(m), RE;
	vector <pair <pair <int, int>, pair <int,  int> > > Q;
	
	for (auto &p: E) scanf ("%d %d %d", &p.se.fi, &p.se.se, &p.fi);
	RE = E;
	sort(RE.begin(), RE.end());
	scanf ("%d", &q);
	rep(i,0,q)
	{
		int k;
		scanf ("%d", &k);
		rep(j,0,k)
		{
			int e;
			scanf ("%d", &e);
			e--;
			Q.pb({{E[e].fi, i}, E[e].se});
		}
	}
	sort(Q.begin(), Q.end());
	
	auto add = RE.begin();
	auto check = Q.begin();
	rep(val,0,N)
	{
		while (check!=Q.end() && check->fi.fi==val)
		{
			int query = check->fi.se;
			int cnt = 0;
			while (check!=Q.end() && check->fi.fi==val && check->fi.se==query)
			{
				if (!unia(check->se.fi, check->se.se))
				{
					Cons[query]++;
				}
				cnt++;
				check++;
			}
			rep(i,0,cnt) rev();
		}
		
		while (add!=RE.end() && add->fi==val)
		{
			unia(add->se.fi, add->se.se);
			add++;
		}
	}
	
	rep(i,0,q)
	{
		if (Cons[i]==0) printf ("YES\n");
		else printf ("NO\n");
	}
}