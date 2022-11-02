#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
void solve(){
	string a,b,c;
	int cnt[26]={},n;
	cin>>n;
	cin>>a>>b;
	rep(i,0,n)cnt[a[i]-'a']++;
	bool f=0;
	rep(i,0,26)f|=(cnt[i]>1);
	rep(i,0,n)cnt[b[i]-'a']--;
	rep(i,0,26){
		if(cnt[i]){
			cout<<"NO\n";RE;
		}
	}
	if(f){
		cout<<"YES\n";
	}else{
		int ans=0;
		c=a;
		sort(ALL(c));
		rep(i,0,n){
			if(c[i]!=a[i]){
				rep(j,i+1,n)if(c[i]==a[j]){
					for(int k=j-1;k>=i;k--)swap(a[k],a[k+1]),ans++;
					break;
				}
			}
		}
		rep(i,0,n){
			if(c[i]!=b[i]){
				rep(j,i+1,n)if(c[i]==b[j]){
					for(int k=j-1;k>=i;k--)swap(b[k],b[k+1]),ans++;
					break;
				}
			}
		}
		if(ans&1){
			cout<<"NO\n";
		}else cout<<"YES\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}