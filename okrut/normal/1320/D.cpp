#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define fi first
#define se second
#define debug(...) //fprintf(stderr, __VA_ARGS__)
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5+4;
int With[N];
const ll mod = 1e9+7;

ll H[N];

ll fexp(ll x, int k)
{
	ll ret = 1;
	for (; k>0; k/=2, x = x*x% mod) if (k&1) ret = ret * x % mod;
	return ret;
}
int n;
string s, t;
vector <int> pos; //positions left
pair <int, ll> hasz (int l, int r)
{
	debug ("hasz %d %d\n", l, r);
	auto rp = upper_bound(pos.begin(), pos.end(), r);
	auto lp = lower_bound(pos.begin(), pos.end(), l);
	rp--;
	
	int R = rp - pos.begin();
	int L = lp - pos.begin();
	
	debug ("found %d %d\n", L, R);
	
	
	bool fo = false, eo = false;
	
	if (With[l]==l-1)
	{
		debug ("add left\n");
		
		if (t[L]=='1' and L<=R) L++;
		else fo = true;
	}
	
	
	if (With[r]==r+1)
	{
		debug ("add right\n");
		if (t[R]=='1' and L<=R) R--;
		else eo = true;
	}
	
	if (R<L and eo and fo) return {0,0};
	
	
	ll hasz;
	if (R<L) hasz = 0; 
	else hasz = (mod +H[R+1] - H[L]) % mod * fexp( fexp(2, mod-2), L) % mod;
	
	
	int len = R-L+1;
	if (eo) 
	{
		hasz = (hasz + fexp(2, R-L+1)) % mod;
		len++;
	}
	if (fo)
	{
		hasz = (hasz + hasz + 1) % mod;
		len++;
	}
	
	debug ("hasz = %d %lld\n", len, hasz);
	
	return {len,hasz};
}

int main ()
{
	//ios_base::sync_with_stdio(false);
	
	cin>>n >>s;
	
	
	
	rep(i,0,n)
	{
		With[i] = -2; //nie zostaly usuniete
		if (t.size()>0 and t.back()=='1' and s[i]=='1')
		{
			With[i] = i-1;
			With[i-1] = i;
			
			pos.pop_back();
			t.pop_back();
			continue;
		}
		t.pb(s[i]);
		pos.pb(i);
	}
	
	debug ("Got t: ");
	cerr<<t <<"\n";
	
	
	H[0] = 0;
	
	rep(i,0,(int)t.size()) H[i+1] = (H[i] + ll(t[i] - '0') * fexp(2, i)) % mod;
	
	
	rep(i,0,(int)t.size()+1) debug ("%lld ", H[i]);
	debug ("\n");
	
	int q;
	cin>>q;
	
	if (pos.size()==0)
	{
		rep(i,0,q) cout<<"Yes\n";
		return 0;
	}
	
	rep(i,0,q)
	{
		int l1, l2, len;
		cin>>l1 >>l2 >>len;
		
		l1--, l2--;
		
		if (len==1) 
		{
			if (s[l1]==s[l2]) cout<<"Yes\n";
			else cout<<"No\n";
			continue;
		}
		
		if (hasz(l1, l1+len-1)==hasz(l2, l2+len-1)) cout <<"Yes\n";
		else cout<<"No\n";
	}
	
	
}