#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back
#define fo(i, n) for(int i = 1; i <= n; ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 200200;
const int mod = 1e9 + 7;
int ok[N];
int n, a[N], b[N];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	fo(i, n)
		cin >> a[i];
	fo(i, n)
		cin >> b[i];
	vector<int> q;
	fo(i, n)
		if(a[i] != b[i])
			q.pb(i);
	if(q.size() == 1)
	{
		fo(i, n)
			if(a[i] == b[i])
				ok[a[i]] = 1;
		fo(i, n)
			if(a[i] == b[i])
				cout << a[i] << " ";
			else
			{
				for(int j = 1; j <= n; ++j)
				{
					if(j != a[i] && j != b[i] && !ok[j])
						cout << j << ' ', j = n + 1;
				}
			}
		return 0;
	}
	fo(i, n)
		if(a[i] == b[i])
			ok[a[i]] = 1;
	for(int i = 1; i <= n; ++i)
	{
		if(!ok[a[q[0]]] && !ok[b[q[1]]])
		{
			if(i == q[0])
				cout << a[i];
			else 
				cout << b[i];
			cout << ' ';
		} 
		else
		{
			if(i == q[0])
				cout << b[i];
			else
				cout << a[i];
			cout << ' ';
		}
	}
	return 0;
}