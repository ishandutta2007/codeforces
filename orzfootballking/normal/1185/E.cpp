#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
V<P<int,int> > v[30];
char c[2005][2005];
P<P<int,int> ,P<int,int> > ans[30];
bool cmp(P<int,int> x,P<int,int> y){
	RE x.S<y.S;
}
void solve(){
	int n,m;bool ff[30]={};
	scanf("%d%d",&n,&m);
	FOR(i,0,25)v[i].clear();
	FOR(i,1,n){
		scanf("%s",c[i]+1);
		FOR(j,1,m){
			if(c[i][j]!='.')v[c[i][j]-'a'].PB(MP(i,j));
		}
	}
	int ansl=-1;
	FOR(i,0,25){
		if(!v[i].size())continue;
		sort(ALL(v[i]),cmp);
		bool f1,f2;P<int,int> anst;
		f1=f2=1;
		for(int j=1;j<v[i].size();j++){
			if(v[i][j].F!=v[i][j-1].F){
				f1=0;break;
			}
		}
		if(f1){
			FOR(j,v[i][0].S,v[i][v[i].size()-1].S){
				if(c[v[i][0].F][j]=='.'||c[v[i][0].F][j]<i+'a'){
					f1=0;break;
				}
			}
			anst=MP(v[i][0].S,v[i][v[i].size()-1].S);
		}
		sort(ALL(v[i]));
		for(int j=1;j<v[i].size();j++){
			if(v[i][j].S!=v[i][j-1].S){
				f2=0;break;
			}
		}
		if(f2){
			FOR(j,v[i][0].F,v[i][v[i].size()-1].F){
				if(c[j][v[i][0].S]=='.'||c[j][v[i][0].S]<i+'a'){
					f2=0;break;
				}
			}
		}
		if(!(f1|f2)){
			cout<<"NO\n";RE;
		}
		if(f1)ans[i]=(MP(MP(v[i][0].F,anst.F),MP(v[i][0].F,anst.S)));
		else ans[i]=(MP(MP(v[i][0].F,v[i][0].S),MP(v[i][v[i].size()-1].F,v[i][0].S)));
		ansl=i;ff[i]=1;
	}
	cout<<"YES\n"<<ansl+1<<'\n';
	for(int i=0;i<=ansl;i++){
		if(!ff[i]){
			cout<<ans[ansl].F.F<<' '<<ans[ansl].F.S<<' '<<ans[ansl].F.F<<' '<<ans[ansl].F.S<<'\n';continue;
		}
		cout<<ans[i].F.F<<' '<<ans[i].F.S<<' '<<ans[i].S.F<<' '<<ans[i].S.S<<'\n';
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	RE 0;
}