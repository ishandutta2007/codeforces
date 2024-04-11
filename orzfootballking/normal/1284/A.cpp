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
string a[25],b[25];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	FOR(i,0,n-1)cin>>a[i];
	FOR(i,0,m-1)cin>>b[i];
	int q;
	scanf("%d",&q);int x;
	FOR(i,1,q){
		scanf("%d",&x);
		cout<<a[(x-1)%n]<<b[(x-1)%m]<<'\n';
	}
	RE 0;
}