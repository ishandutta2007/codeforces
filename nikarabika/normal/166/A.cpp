#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int main(){
	ios_base::sync_with_stdio(false);
	int k, n;
	cin>>n>>k;
	k--;
	pie a[n];
	rep(i, n){
		int fi, se;
		cin>>fi>>se;
		a[i]=MP(fi, 51-se);
	}
	sort(a, a+n);
	reverse(a, a+n);
	int fi=a[k].L;
	int se=a[k].R;
	int ans=0;
	for(int i=k-1; i>=0; i--)
		if(a[i].L==fi && a[i].R==se)
			ans++;
	FOR(i, k+1, n-1)
		if(a[i].L==fi && a[i].R==se)
			ans++;
	cout<<ans+1<<endl;
	return 0;
}