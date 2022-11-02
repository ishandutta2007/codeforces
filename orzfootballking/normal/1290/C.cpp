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
V<int> v[300005];
int n,cost[600005],fa[600005],m;
int get(int a){
	if(fa[a]==a)RE a;
	RE fa[a]=get(fa[a]);
}
int gmin(int p){
	RE min(cost[get(p)],cost[get(p+m)]);
}
void up(int a,int b){
	a=get(a);b=get(b);
	if(a==b)RE;
	if(cost[a]>cost[b]){
		cost[a]+=cost[b];fa[b]=a;
	}else{
		cost[b]+=cost[a];fa[a]=b;
	} 
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
	int len,x;
	cin>>n>>m>>s;
	FOR(i,1,m){
		cin>>len;
		FOR(j,1,len){
			cin>>x;
			v[x].PB(i);
		}
	}
	FOR(i,1,m)fa[i]=i;
	FOR(i,m+1,(m<<1))fa[i]=i,cost[i]=1;
	fa[(m<<1)+1]=(m<<1)+1;
	cost[(m<<1)+1]=1000000000;
	int ans=0;
	FOR(i,1,n){
		if(v[i].size()==1){
			ans-=gmin(v[i][0]);
			if(s[i-1]=='1')up(v[i][0]+m,(m<<1)+1);else up(v[i][0],(m<<1)+1);
			ans+=gmin(v[i][0]);
		}else if(v[i].size()==2){
			if(s[i-1]=='1'){
				if(get(v[i][0])!=get(v[i][1])){
					ans-=gmin(v[i][0])+gmin(v[i][1]);
					up(v[i][0],v[i][1]);up(v[i][0]+m,v[i][1]+m);
					ans+=gmin(v[i][0]);
				}
			}else{
				if(get(v[i][0])!=get(v[i][1]+m)){
					ans-=gmin(v[i][0])+gmin(v[i][1]);
					up(v[i][0],v[i][1]+m);up(v[i][0]+m,v[i][1]);
					ans+=gmin(v[i][0]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	RE 0;
}