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
int f[200005][26],t[26];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	cin>>s;
	int q;
	cin>>q;
	int l,r;
	f[0][s[0]-'a']=1;
	for(int i=1;i<s.size();i++){
		FOR(j,0,25)f[i][j]=f[i-1][j];
		f[i][s[i]-'a']++;
	}
	FOR(i,1,q){
		cin>>l>>r;
		if(l==r){
			cout<<"Yes\n";continue;
		}
		l--;r--;
		FOR(j,0,25)t[j]=f[r][j]-f[l][j];
		t[s[l]-'a']++;
		int count=0;
		FOR(j,0,25){
			if(t[j])count++;
		}
		if(count>2){
			cout<<"Yes\n";
		}else{
			if(count==1){
				cout<<"No\n";
			}else{
				if(s[l]==s[r]){
					cout<<"No\n";
				}else cout<<"Yes\n";
			}
		}
	}
	RE 0;
}