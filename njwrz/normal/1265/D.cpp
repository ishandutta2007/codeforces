#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a>b){
		if(a-b==1&&!c&&!d){
			cout<<"YES\n";
			FOR(i,1,b)cout<<"0 1 ";
			cout<<0;
		}else cout<<"NO";
		RE 0;
	} 
	if(c<d){
		if(d-c==1&&!a&&!b){
			cout<<"YES\n";
			FOR(i,1,c)cout<<"3 2 ";
			cout<<3;
		}else cout<<"NO";
		RE 0;
	}
	b-=a;c-=d;
	if(abs(b-c)>1){
		cout<<"NO";RE 0;
	}
	cout<<"YES\n";
	if(b>c)cout<<"1 ";
	FOR(i,1,a)cout<<"0 1 ";
	FOR(i,1,min(b,c))cout<<"2 1 ";
	FOR(i,1,d)cout<<"2 3 ";
	if(c>b)cout<<2;
	RE 0;
}