#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
#define slld(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define For(i, st, en) for(ll i=st; i<en; i++)
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long
#define int long long
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;

int a[100005];
vector<int> ans;


signed main(){
	fast;
	int n, k;
	cin>>n>>k;
	int tot = 0;
	For(i, 0, n){
		cin>>a[i];
		tot+=a[i];
	}
	if(tot%k!=0){
		cout<<"No";
		return 0;
	}
	int req = tot/k;
	int val = 0;
	int ct = 0;
	For(i, 0, n){
		val+=a[i];
		ct++;
		if(val==req){
			ans.pb(ct);
			val=0;
			ct=0;
		}
		else if(val>req){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	For(i, 0, ans.size()){
		cout<<ans[i]<<" ";
	}
	return 0;
}