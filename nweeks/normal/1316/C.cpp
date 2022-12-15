#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n,m,p;
	cin >> n >> m >> p;
	vector<int> a(n), b(m);
	for (auto &v : a) cin >> v;
	for (auto &v : b) cin >> v;
	int i(0), j(0);
	while (a[i]%p==0)++i;
	while (b[j]%p==0)++j;
	cout<<i+j<<endl;
}