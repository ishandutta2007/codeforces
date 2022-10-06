#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(ut)(b);i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
#define ALL(c) c.begin(),c.end()
using namespace std;
typedef long long LL;
typedef LL ut;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef priority_queue<pr,Vpr,greater<pr> > PQ;
const int SIZE=2*1e5;
PQ qu;
LL ans[SIZE],maxer[SIZE],miner[SIZE];
int main(){
	int n,a,b;
	cin >> n;
	REP(i,n){
		cin >> a >> b;
		maxer[i]=a+b;
		miner[i]=a;
		qu.push(pr(a+b,i));		
	}
	while(!qu.empty()){
		int now=qu.top().second;
		int val=qu.top().first;
		qu.pop();
		if(ans[now]) continue;
		ans[now]=val;
		if(now!=n-1)
			qu.push(pr(val+1,now+1));
		if(now!=0)
			qu.push(pr(val+1,now-1));	
	}
	LL anser=0;
	REP(i,n){
		anser+=ans[i]-miner[i];
		if(ans[i]<miner[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << anser << endl;

	REP(i,n){
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}