#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
//void read(ll& x){ scanf("%I64d",&x); }
void read(ll& x){ cin >> x; }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

ll toL[5010];
ll toR[5010];
ll fromL[5010];
ll fromR[5010];

ll pos[5010];
int n;

ll dp[5010][5];
ll tmp[5010][5];

ll inf = (1LL<<60);

int nt;

int main(){
	int s,e;
	read(n, s, e);
	for(int i=1; i<=n; ++i) read(pos[i]);

	for(int i=1; i<=n; ++i){
		int a;
		read(a);
		fromL[i] = a+pos[i];
	}

	for(int i=1; i<=n; ++i){
		int a;
		read(a);
		fromR[i] = a-pos[i];
	}

	for(int i=1; i<=n; ++i){
		int a;
		read(a);
		toL[i] = a+pos[i];
	}

	for(int i=1; i<=n; ++i){
		int a;
		read(a);
		toR[i] = a-pos[i];
	}

	for(int j=0; j<=n; ++j){
		for(int a=0; a<5; ++a)
			dp[j][a] = inf;
	}

	dp[0][2] = 0;

	for(int i=1; i<=n; ++i){

		if(i == s){
			for(int j=0; j<=n; ++j) for(int dt=0; dt<5; ++dt){
				int a=j, b=j+dt-2;
				ll &y = tmp[j][dt];
				y=inf;
				if(a<0 || b<0 || (a==0 && b==0 && i!=n)) continue;

				if(b-1-a>=-2 && b>=1)
					y=min(y, toR[i] + dp[a][b-1-a+2]);

				if(b-1-a>=-2 && a+1<=n)
					y=min(y, toL[i] + dp[a+1][b-1-a+2]);
				}
			memcpy(dp, tmp, sizeof(tmp));
			continue;
		}

		if(i == e){
			for(int j=0; j<=n; ++j) for(int dt=0; dt<5; ++dt){
				int a=j, b=j+dt-2;
				ll &y = tmp[j][dt];
				y=inf;
				if(a<0 || b<0 || (a==0 && b==0 && i!=n)) continue;

				if(a-1>=0 && b-a+1<=2)
					y=min(y, fromR[i] + dp[a-1][b-a+3]);

				if(b+1<=n && b+1-a<=2)
					y=min(y, fromL[i] + dp[a][b+1-a+2]);
			}
			memcpy(dp, tmp, sizeof(tmp));
			continue;
		}

		for(int j=0; j<=n; ++j) for(int dt=0; dt<4; ++dt){
			int a=j, b=j+dt-2;
			ll &y = tmp[j][dt];
			y=inf;
			if(a<0 || b<0 || (a==0 && b==0 && i!=n)) continue;
			if(b)
				y = min(y, dp[j][dt] + fromL[i] + toR[i]);
			if(a)
				y = min(y, dp[j][dt] + fromR[i] + toL[i]);
			if(a && b)
				y = min(y, dp[a-1][dt] + fromR[i] + toR[i]);
			if(a+1<=n && b+1<=n)
				y = min(y, dp[j+1][dt] + fromL[i] + toL[i]);
		}

		memcpy(dp, tmp, sizeof(tmp));
	}

	cout << dp[0][2] << endl;
	return 0;
}