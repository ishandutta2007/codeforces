#pragma GCC optimize("Ofast")
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
void solve(){
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    y-=x;
    if(y%(a+b)==0){
        cout<<y/(a+b);
    }else cout<<-1;
    cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
    cin>>t;
    while(t--)solve();
	RE 0;
}