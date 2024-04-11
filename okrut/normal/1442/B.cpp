#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod = 998244353;
const int N = 2e5+100;

int Perm[N], Pos[N];

int main ()
{
	//ios_base::sync_with_stdio(false);
	int t;
	scanf ("%d", &t);
	rep(q,0,t)
	{
		int n, k;
		scanf ("%d %d", &n, &k);
		
		set <pair <int, int> > A, C;
		
		rep(i,0,n) 
		{
			scanf ("%d", &Perm[i]);
			A.insert({i, Perm[i]});
			Pos[Perm[i]] = i;
			
			C.insert({i, Perm[i]});
		}
		
		vector <int> B(k);
		for (int &b: B) scanf ("%d", &b);
		for (int b: B) C.erase({Pos[b],b});
		
		ll res = 1;
		
		for (int b: B)
		{
			ll f = 0;
			ll r = 0;
			
			auto a = A.lower_bound({Pos[b], N});
			auto c = C.lower_bound({Pos[b], N});
			
			debug ("%d %d\n", a->se, c->se);
			
			if (a!=A.end() and c!=C.end() and a->se==c->se) r = a->se;
			
			if (a!=A.begin() and c!=C.begin()) {
				a--;
				a--; 
				c--;
				if (a->se == c->se) f = a->se;
			}
			/*
			debug ("Doing %d: \n", b);
			for (auto p: A) debug ("%d ", p.se);
			debug ("\n");
			for (auto p: C) debug ("%d ", p.se);
			debug ("\nGot %lld %lld\n", f, r);
			*/
			
			if (f>0) {
				A.erase({Pos[f], f});
				C.erase({Pos[f], f});
			} else if (r>0) {
				A.erase({Pos[r], r});
				C.erase({Pos[r], r});
			}
			
			C.insert({Pos[b], b});
			
			ll w = 0;
			if (r>0) w++;
			if (f>0) w++;
			
			res= res * w % mod;
		}
		printf ("%lld\n", res);
	}
}