#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;
ll a[2000000];
std::vector<ll> w(24, 0);
std::vector<ll> t(24, 0);
ll b[2000000];
ll n;
ll merge(ll s1, ll e1, ll s2, ll e2)
{
ll i, j, k;
  ll invc = 0;
  i = s1;
  j = s2;
  k = s1;
  while ((i <= e1) && (j <= e2))
  {
    if (a[i] <= a[j])
      b[k++] = a[i++];
    else
    {
      b[k++] = a[j++];
      invc = invc + (e1 - i + 1);
    }
  }
  while (i <= e1)
    b[k++] = a[i++];
  while (j <= e2)
    b[k++] = a[j++]; 
  for (i=s1; i <= e2; i++)
    a[i] = b[i];
  return invc;
}
ll aps(ll n)
{
	ll j = 0;
	while(n != 1) {
		j++;
		n >>= 1;
	}
	return j;
}

ll calc(ll s, ll e)
{
	ll re = 0;
	for (ll i = s; i <= e; ++i)
	{
		ll j = 1;
		while(i <= e && a[i] == a[i+1])
			j++,i++;
		re+=(e-i)*j;
	}
	return re;
}

ll mergesort(ll s, ll e)
{
	if(s == e)
		return 0;
	ll m = (s+e)/2; 
	ll inv = mergesort(s, m);
	inv += mergesort(m + 1, e);
	inv += merge(s, m, m+1, e);
	w[aps(e-s+1)] += inv;
	t[aps(e-s+1)] += calc(s, e);
	return inv;
}

ll getres(ll q)
{
	std::vector<ll> nw(n+1, 0);
	for (ll i = 0; i <= q; ++i)
		nw[i] = t[i] - w[i];
	for (ll i = q+1; i <= n; ++i)
		nw[i] = w[i] - w[i-1] + nw[i-1];
	for (ll i = 0; i <= n; ++i)
		w[i] = nw[i];
	return nw[n];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#endif
	cin >> n;
	for (ll i = 0; i < (1<<n); ++i)
		cin >> a[i];
	mergesort(0, (1 << n)-1);
	ll m;
	cin >> m;
	ll q;
	for (ll i = 0; i < m; ++i)
	{
		cin >> q;
		cout << getres(q) << "\n";
	}
}