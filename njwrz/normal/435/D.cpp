#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
int a[405][405],n,m,p[405][405][8],mod=8;
int fx[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
bool check(int i,int j){
	RE (i>=1&&i<=n&&j>=1&&j<=m&&!a[i][j]);
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			char c;
			cin>>c;
			a[i][j]=c-'0';
		}
	}
	FOR(i,0,n+1){
		FOR(j,0,m+1){
			if(i<1||i>n||j<1||j>m)a[i][j]=1;
			if(!a[i][j])continue;
			FOR(k,0,mod-1){
				int t=1,ti=i,tj=j,t1=(k+4)%mod;
				ti+=fx[k][0];tj+=fx[k][1];
				while(ti>=0&&tj>=0&&ti<=n+1&&tj<=m+1&&!a[ti][tj]){
					p[ti][tj][t1]=t;
					t++;ti+=fx[k][0];tj+=fx[k][1];
				}
			} 
		}
	}
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,m){
			if(a[i][j])continue;
			FOR(k,0,mod-1){
				int ti1=i,tj1=j,ti2=i,tj2=j,sum=0,t1=(k+2)%mod,t2=(k+3)%mod;
				ti1+=fx[k][0];tj1+=fx[k][1];ti2+=fx[t1][0];tj2+=fx[t1][1];
				sum=sum+1+(k&1);
				while(check(ti1,tj1)&&check(ti2,tj2)){
					if(p[ti1][tj1][t2]>sum)ans++;
					ti1+=fx[k][0];tj1+=fx[k][1];ti2+=fx[t1][0];tj2+=fx[t1][1];
					sum=sum+1+(k&1);
				}
			} 
		}
	}
	cout<<ans;
	RE 0;
}