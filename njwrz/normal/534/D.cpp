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
V<int> p[200005],ans; 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,x;
	cin>>n;
	FOR(i,1,n){
		cin>>x;
		p[x].PB(i);
	}
	int t=0;
	FOR(i,1,n){
		while(!p[t].size()&&t>=3)t-=3;
		if(!p[t].size()){
			cout<<"Impossible";RE 0;
		}
		ans.PB(p[t].back());
		p[t].pop_back();t++;
	}
	cout<<"Possible\n";
	FOR(i,1,n){
		cout<<ans[i-1]<<' ';
	}
	RE 0;
}