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
void solve(){
	int n;string s;
	cin>>n>>s;
	int maxi=0;
	int last=-1;
	FOR(i,0,n-1){
		if(s[i]=='A'){
			last=i;
		}else{
			if(last!=-1){
				maxi=max(maxi,i-last);
			}
		}
	}
	cout<<maxi<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}