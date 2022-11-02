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
int cnt[32];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	rep(i,1,32){
		cnt[i]=cnt[i/2]+(i&1);
	}
	int n,m;
	cin>>n>>m;
	V<V<int> > v;
	v.resize(n);
	rep(i,0,n)v[i].resize(m);
	char c;
	rep(i,0,n){
		rep(j,0,m){
			cin>>c;
			v[i][j]=c-'0';
		} 
	} 
	if(n>m){
		swap(n,m);
		V<V<int> > t;
		t.resize(n);
		rep(i,0,n)t[i].resize(m);
		rep(i,0,n){
			rep(j,0,n)t[i][j]=v[j][i];
		} 
		v=t;
	}
	V<V<int> > now;
	now.resize(n);
	rep(i,0,n)now[i].resize(m);
	if(n>3){
		cout<<-1;RE 0;
	}
	if(n==1){
		cout<<0;RE 0;
	}
	int mini=1e9;
	if(n==2){
		rep(mask,1,1<<4){
			if(!(cnt[mask]&1))continue;
			now[0][0]=(mask&1)!=0;
			now[0][1]=(mask&2)!=0;
			now[1][0]=(mask&4)!=0;
			now[1][1]=(mask&8)!=0;
			int ans=0;
			rep(j,0,m){
				rep(i,0,n){
					ans+=(now[i][j]!=v[i][j]);
				}
				if(!j||j==m-1)continue;
				int nowt=0;
				rep(i,0,n){
					nowt+=now[i][j];
				}
				int mi=1e9,lst;
				rep(nxt,0,4){
					if((cnt[nxt]+nowt)&1){
						now[0][j+1]=(nxt&1)!=0;
						now[1][j+1]=(nxt&2)!=0;
						int nt=0;
						rep(i,0,n)nt+=now[i][j+1]!=v[i][j+1];
						if(nt<mi){
							mi=nt;lst=nxt;
						}
					}
				}
				now[0][j+1]=(lst&1)!=0;
				now[1][j+1]=(lst&2)!=0;
			}
			gmin(mini,ans);
		}
		cout<<mini<<'\n';
	}else{
		rep(mask,1,1<<6){
			if(!(cnt[mask>>2]&1)||!(cnt[mask&15]&1))continue;
			now[0][0]=(mask&1)!=0;
			now[0][1]=(mask&2)!=0;
			now[1][0]=(mask&4)!=0;
			now[1][1]=(mask&8)!=0;
			now[2][0]=(mask&16)!=0;
			now[2][1]=(mask&32)!=0;
			int ans=0;
			rep(j,0,m){
				rep(i,0,n){
					ans+=(now[i][j]!=v[i][j]);
				}
				if(!j||j==m-1)continue;
				int t1=now[0][j]+now[1][j],t2=now[1][j]+now[2][j];
				int mi=1e9,lst;
				rep(nxt,0,8){
					if(((cnt[nxt%4]+t1)&1)&&((cnt[nxt>>1]+t2)&1)){
						now[0][j+1]=(nxt&1)!=0;
						now[1][j+1]=(nxt&2)!=0;
						now[2][j+1]=(nxt&4)!=0;
						int nt=0;
						rep(i,0,n)nt+=now[i][j+1]!=v[i][j+1];
						if(nt<mi){
							mi=nt;lst=nxt;
						}
					}
				}
				now[0][j+1]=(lst&1)!=0;
				now[1][j+1]=(lst&2)!=0;
				now[2][j+1]=(lst&4)!=0;
			}
			gmin(mini,ans);
		}
		cout<<mini<<'\n';
	}
	RE 0;
}