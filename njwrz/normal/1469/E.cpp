#include<bits/stdc++.h>
#define int long long
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
int a[1000005];
bool d[1<<20];
V<int> v;
void solve(){
	for(auto u:v)d[u]=0;
	v.clear();
	int n,k;
	cin>>n>>k;
	FOR(i,1,n){
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	int t=1;
	bool s=0;
	int l;
	FOR(i,1,k){
		t=t*2;
		if(t>n-k+1){
			l=i;s=1;break;
		}
	}
	if(!s){
		FOR(i,1,n-k+1){
			int now=0;
			FOR(j,i,i+k-1){
				now=(now<<1)+(1^a[j]);
			}
			v.PB(now);
			d[now]=1;
		}
		rep(i,0,1<<k){
			if(!d[i]){
				cout<<"YES\n";
				for(int j=k-1;j>=0;j--){
					if(i&(1<<j)){
						cout<<1;
					}else cout<<0;
				}
				cout<<'\n';RE;
			}
		}
		cout<<"NO\n";
		RE;
	}else{
		int cnt=k-l;
//		cout<<l<<' '<<cnt<<'\n';
		int one=0;
		FOR(i,0,n-l){
			if(a[i]==1){
				one++;
			}else one=0;
//			cout<<one<<' ';
			if(one>=cnt){
				int now=0;
				FOR(j,i+1,i+l){
					now=(now<<1)+(1^a[j]);
				}
				v.PB(now);
//				cout<<now<<'\n';
				d[now]=1;
			}
		}
		rep(i,0,1<<l){
			if(!d[i]){
//				cout<<i<<'\n';
				cout<<"YES\n";
				FOR(j,1,cnt)cout<<0;
				for(int j=l-1;j>=0;j--){
					if(i&(1<<j))cout<<1;
					else cout<<0;
				}
				cout<<'\n';RE;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}