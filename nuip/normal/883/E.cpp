#include <bits/stdc++.h>
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,b) reps(i,0,b)
#define pb push_back
#define all(c) c.begin(),c.end()
using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> cnt(200),re(200);
	for(char c:s) ++cnt[c];
	int m;
	cin>>m;
	int al=0;
	while(m--){
		string t;
		cin>>t;
		vector<int> ct(200);
		for(char c:t) ++ct[c];
		int ng=0;
		rep(i,n)if(s[i]!='*' && s[i]!=t[i]) ng=1;
		for(char c:s) if(c!='*' && ct[c]!=cnt[c]) ng=1;
		if(!ng){
			//cout<<t<<endl;
			rep(i,200)if(ct[i]&&cnt[i]==0) re[i]++;
			++al;
		}
	}
	int ret=0;
	rep(i,200)if(re[i]==al) ++ret;
	assert(ret<200);
	cout<<ret<<endl;
}