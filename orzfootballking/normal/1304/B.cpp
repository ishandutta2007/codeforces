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
int n,m;
string s[105];
bool f[105];
string ans;
bool check(string x,string y){
    rep(i,0,m)if(x[i]!=y[m-i-1])RE 0;
    RE 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
    rep(i,0,n)cin>>s[i];
	rep(i,0,n){
		if(check(s[i],s[i])){
			ans=s[i];f[i]=1;
			break;
		}
	}
    rep(i,0,n){
        if(f[i])continue;
        rep(j,i+1,n){
            if(check(s[i],s[j])){
                f[i]=1;f[j]=1;
                ans=s[i]+ans+s[j];
            }
        }
    }
	cout<<ans.size()<<'\n';
    cout<<ans;
	RE 0;
}