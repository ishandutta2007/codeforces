#pragma GCC optimize(2)
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
V<int> v[30];
void solve(){
	FOR(i,1,26)v[i].clear();
	string s,t;
	cin>>s>>t;
	for(int i=0;i<s.size();i++)v[s[i]-'a'+1].PB(i);
	int l=0,f,ans=1;
	V<int>::iterator iter;
	for(int i=0;i<t.size();i++){
		f=t[i]-'a'+1;
		if(!v[f].size()){
			cout<<"-1\n";RE ;
		}
		iter=lower_bound(ALL(v[f]),l);
		if(iter==v[f].end()){
			l=v[f][0]+1;ans++;
		}else{
			l=(*iter)+1;
		}
	}
	cout<<ans<<'\n';
} 
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}