
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int r[8][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	for (int i=1;i<=7;++i){
		for (int j=0;j<3;++j){
			r[i][j]=(i>>j&1);
		}
		cout<<endl;
	}
	cin>>t;
	while (t--){
		int a,b,c,ans=0;
		cin>>a>>b>>c;
		for (int i=1;i<(1<<7);++i){
			int u=0,v=0,w=0,tot=0;
			for (int j=0;j<7;++j){
				if (i>>j&1){
					tot++;
					u+=r[j+1][0];
					v+=r[j+1][1];
					w+=r[j+1][2];
				}
			}
			if (u<=a&&v<=b&&w<=c) ans=max(tot,ans);
		}
		cout<<ans<<endl;
	}
}