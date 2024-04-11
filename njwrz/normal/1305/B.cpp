#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int cnt1[1005],cnt2[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	FOR(i,1,n)cnt1[i]=cnt1[i-1]+(s[i-1]=='(');
	for(int i=n;i>=1;i--)cnt2[i]=cnt2[i+1]+(s[i-1]==')');
	FOR(i,0,n){
		if(cnt1[i]==cnt2[i+1]){
			if(!cnt1[i]){
				cout<<0;RE 0;
			}else{
				cout<<"1\n";
				cout<<cnt1[i]*2<<'\n';
				rep(j,0,i)if(s[j]=='(')cout<<j+1<<' ';
				rep(j,i,n)if(s[j]==')')cout<<j+1<<' ';
				RE 0;
			}
		}
	}
	RE 0;
}