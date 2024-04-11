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
int x,n;
void solve(){
	cin>>n;
	int last;
	cin>>last;
	int l=-1,r;
	FOR(i,2,n){
		cin>>x;
		if(abs(x-last)>1){
			l=i-1;r=i;
		}
		last=x;
	}
	if(l==-1){
		puts("NO");
	}else{
		puts("YES");
		cout<<l<<' '<<r<<'\n';
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}