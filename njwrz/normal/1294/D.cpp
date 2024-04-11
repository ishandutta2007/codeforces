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
int a[400005],f[400005];
set<P<int,int> > s;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,x;
	cin>>n>>x;
	FOR(i,1,n)cin>>a[i],a[i]%=x;
	int ans=0;
	FOR(i,0,x-1)s.insert(MP(0,i));
	FOR(i,1,n){
		s.erase(MP(f[a[i]],a[i]));f[a[i]]++;
		s.insert(MP(f[a[i]],a[i]));
		P<int,int> t=(*s.begin());
		cout<<t.F*x+t.S<<'\n';
	} 
	RE 0;
}