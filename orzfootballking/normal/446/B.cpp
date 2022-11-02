#pragma GCC optimize(3)
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
priority_queue<int> ql,qh;
int a[1005][1005];
int an1[1000005],an2[1000005];
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,m,k,p;
	cin>>n>>m>>k>>p;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>a[i][j];
		}
	}
	int x;
	FOR(i,1,n){
		x=0;
		FOR(j,1,m){
			x=x+a[i][j];
		}
		qh.push(x);
	}
	FOR(i,1,k){
		int t=qh.top();qh.pop();
		an1[i]=an1[i-1]+t;
		qh.push(t-m*p);
	}
	FOR(j,1,m){
		x=0;
		FOR(i,1,n){
			x=x+a[i][j];
		}
		ql.push(x);
	}
	int ans=an1[k];
	FOR(i,1,k){
		int t=ql.top();ql.pop();
		an2[i]=an2[i-1]+t;
		ql.push(t-n*p);
		ans=max(ans,an1[k-i]+an2[i]-i*(k-i)*p);
	}
	cout<<ans;
	RE 0;
}