
#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

struct alpha{
	alpha* next[2];
};
alpha *getnode() {
	alpha *temp = new alpha;
	for (ll i = 0; i < 2; ++i)
		temp->next[i] = NULL;
	return temp;
}
alpha* addword(alpha* root, ll s){
	alpha *curr = root;
	for (ll i = 40; i >= 0; --i)
	{
		if(curr->next[((s & (1ll << i)) >> i)] == NULL)
			curr->next[((s & (1ll << i)) >> i)] = getnode();
		curr = curr->next[((s & (1ll << i)) >> i)];
	}
	return root;
}

bool check(alpha* root, ll s)
{
	alpha *curr = root;
	for (ll i = 40; i >= 0 ; --i)
	{
		if(curr->next[((s & (1ll << i)) >> i)] == NULL)
			return false;
		curr = curr->next[((s & (1ll << i)) >> i)];
	}
	return true;
}

ll maxw(alpha* root, ll s){
	alpha *curr = root;
	ll res = 0;
	for (ll i = 40; i >= 0; --i)
	{
		if(curr->next[1ll - (((s & (1ll << i)) >> i))] != NULL)
		{
			res += (1ll << i);
			curr = curr->next[1ll - ((s & (1ll << i)) >> i)];
		}
		else
			curr = curr->next[((s & (1ll << i)) >> i)];
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	#ifdef PIYUSH_HOME
		I_O;
	#endif
	ll n; cin >> n;
	ll to = 0;
	vector<ll> a(n); for (ll o = 0; o < n; ++o) { cin >> a[o]; to ^= a[o];}
	alpha *root = getnode();
	root = addword(root, 0ll);
	ll m = maxw(root, to);
	ll t = 0;
	for (ll i = 0; i < n; ++i)
	{
		to ^= a[i];
		t ^= a[i];
		root = addword(root, t);
		m = max(m, maxw(root, to));
	}
	cout << m << "\n";
}