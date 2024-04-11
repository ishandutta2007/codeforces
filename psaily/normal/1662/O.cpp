#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define SZ(x) ((int)x.size())
#define pb push_back
#define all(x) x.begin(),x.end()
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef vector<int> VI;
const int inf=1<<30;
using pii = pair<int,int>;
const int N=2e5+5;
int n,x,a[N];
ll ans;
int cir[22][361];
int cut[22][361];
int vis[22][361];
int solve(){
	memset(cir,0,sizeof(cir));
	memset(cut,0,sizeof(cir));
	memset(vis,0,sizeof(cir));
	scanf("%d",&n);
	char s[2];
	int z,x,c;
	for(int i=1;i<=n;i++){
		scanf("%s%d%d%d",s,&z,&x,&c);
		if(s[0]=='C'){
			if(c<x)c+=360;
			for(int i=x;i<c;i++)
				cir[z][i%360]=1;
		} else{
			for(int i=z;i<x;i++)
				cut[i][c]=1;
		}
	}
	queue<pii>q;
	q.push({0,0});
	while(!q.empty()){
		int pos=q.front().first;
		int now=q.front().second;
		q.pop();
		// printf("%d %d ok\n",pos,now);
		int t=now;
		while(t<=now+360-1){
			vis[pos][t%360]=1;
			if(!cir[pos+1][t%360]){
				if(!vis[pos+1][t%360]){
					vis[pos+1][t%360]=1;
					q.push({pos+1,t%360});
					if(pos==20)return 1;
				}
			}
			if(pos)
				if(!cir[pos][t%360]){
					if(!vis[pos-1][t%360]){
						vis[pos-1][t%360]=1;
						q.push({pos-1,t%360});
					}
				}
			t++;
			if(cut[pos][t%360])break;
		}			
		t=now;
		while(t>=now-360+1){
			vis[pos][(t+360)%360]=1;
			if(!cir[pos+1][(t+360)%360]){
				if(!vis[pos+1][(t+360)%360]){
					vis[pos+1][(t+360)%360]=1;
					q.push({pos+1,(t+360)%360});
					if(pos==20)return 1;
				}
			}
			if(pos)
				if(!cir[pos][(t+360)%360]){
					if(!vis[pos-1][(t+360)%360]){
						vis[pos-1][(t+360)%360]=1;
						q.push({pos-1,(t+360)%360});
					}
				}
			if(cut[pos][(t+360)%360])break;
			t--;
		}
	}
	return 0;
}
int main() {
	 
	int _;
	for (scanf("%d",&_);_;_--) {
		puts(solve()?"YES":"NO");
	}
	return 0;	
}