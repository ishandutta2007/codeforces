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
int n,m;
V<int> v[100005];
int f[100005],p[100005],d[505][505];
void fill(int i,int j,int z){
	if(d[i][j]==-1||d[i][j]>z)d[i][j]=z;
}
void dfs(int e){
	if(p[e])return;
	p[e]=1;
	for(int i=0;i<v[e].size();i++){
		dfs(v[e][i]);
	}
}
int main(){
	int k,q=0;
	cin>>n>>k>>m;
	FILL(d,-1);
	int x,y,z;
	FOR(i,1,m){
		cin>>x;
		FOR(j,1,x)f[++q]=i;
	}
	FOR(i,1,k){
		cin>>x>>y>>z;
		if(z==0){
			v[x].PB(y);
			v[y].PB(x); 
		}
		fill(f[x],f[y],z);
		fill(f[y],f[x],z);
	}
	FOR(i,1,n){
		if(f[i]!=f[i-1]){
			FILL(p,0);
			dfs(i);
			FOR(j,i+1,n){
				if(f[i]!=f[j])break;
				if(!p[j]){
					cout<<"No";return 0;
				}
			}
		}
	}
	FOR(i,1,m){
		FOR(j,1,m){
			FOR(k,1,m){
				if(i==j||i==k||j==k||d[i][j]==-1||d[i][k]==-1)continue;
				fill(j,k,d[i][j]+d[i][k]);
			}
		}
	}
	cout<<"Yes\n";
	FOR(i,1,m){
		FOR(j,1,m){
			if(i==j)cout<<"0 ";
			else cout<<d[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}