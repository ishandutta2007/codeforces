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
int n,m,s,ans;
int c[355][100005];
deque<int> v[355];
int deal(int k){
	RE (k+ans-1)%n+1;
}
//void check(){
//	FOR(i,0,m-1){
//		FOR(j,0,v[i].size()-1){
//			cout<<v[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n';
//}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int x;
	cin>>n;s=int(sqrt(n));
	m=n/s+(n%s!=0);
	FOR(i,0,n-1){
		cin>>x; 
		v[i/s].PB(x);
		c[i/s][x]++;
	}
	int q,y,z;
	cin>>q;
	FOR(t,1,q){
		cin>>x;
		if(x==1){
			cin>>x>>y;
			x=deal(x);y=deal(y);x--;y--;
			if(x>y)swap(x,y);
			int a=x/s,b=y/s;
			if(a==b){
				int last=v[a][y%s];
				v[a].erase(v[a].begin()+y%s);
				v[a].insert(v[a].begin()+x%s,last);
			}else{
				int last=v[a].back();
				v[a].insert(v[a].begin()+x%s,v[b][y%s]);c[a][v[b][y%s]]++;
				v[a].pop_back();c[a][last]--;
				FOR(j,a+1,b-1){
					v[j].PF(last);
					c[j][last]++;
					last=v[j].back();
					v[j].pop_back();
					c[j][last]--;
				}
				c[b][v[b][y%s]]--;v[b].erase(v[b].begin()+y%s);
				v[b].PF(last);
				c[b][last]++;
			}
//			check();
		}else{
			cin>>x>>y;
			x=deal(x);y=deal(y);x--;y--;
			if(x>y)swap(x,y);
			int a=x/s,b=y/s;
			int k;
			cin>>k;k=deal(k);
			ans=0;
			if(a==b){
				FOR(j,x%s,y%s){
					if(v[a][j]==k)ans++;
				}
			}else{
				FOR(j,x%s,v[a].size()-1){
					if(v[a][j]==k)ans++;
				}
				FOR(j,0,y%s){
					if(v[b][j]==k)ans++;
				}
				FOR(j,a+1,b-1){
					ans+=c[j][k];
				}
			}
			cout<<ans<<'\n';
		}
	}
	RE 0;
}