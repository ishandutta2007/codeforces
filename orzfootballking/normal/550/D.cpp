#pragma GCC optimize("Ofast,unroll-loops")
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
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int k;
	cin>>k;
	if(!(k&1)){
		cout<<"NO";RE 0;
	}
	cout<<"YES\n";
	cout<<4*k-2<<' '<<(2*k-1)*k<<'\n';
	for(int i=1;i<k;i+=2)cout<<i<<' '<<i+1<<'\n';
	for(int i=1;i<k;i++){
		for(int j=k;j<=k*2-2;j++)cout<<i<<' '<<j<<'\n';
	}
	for(int j=k;j<=k*2-2;j++)cout<<j<<' '<<2*k-1<<'\n';
	cout<<2*k-1<<' '<<2*k<<'\n';
	for(int j=1;j<k;j++)cout<<j+2*k<<' '<<2*k<<'\n';
	for(int i=1;i<k;i++){
		for(int j=1;j<k;j++){
			cout<<i+2*k<<' '<<j+3*k-1<<'\n';
		}
	}
	for(int i=1;i<k;i+=2){
		cout<<i+3*k-1<<' '<<i+3*k<<'\n';
	}
	RE 0;
}