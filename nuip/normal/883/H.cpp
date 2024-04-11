#include <bits/stdc++.h>
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,b) reps(i,0,b)
#define pb push_back
#define all(c) c.begin(),c.end()
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	string s;
	cin>>n>>s;
	vector<int> cnt(200);
	for(char c:s)++cnt[c];
	string t,o;
	rep(i,200){
		t+=string(cnt[i]/2,i);
		if(cnt[i]%2) o+=string(1,i);
	}
	auto out=[](string s,string t){
		cout<<s<<t;
		reverse(all(s));
		cout<<s<<" ";
	};
	//cout<<s<<","<<t<<","<<o<<endl;
	if(o.size()){
		int re=0;
		reps(i,1,n+1)if(i>=o.size() && (i-o.size())%2==0 &&
										n%i==0 && n/i%2){
			re=i;
			break;
		}
		cout<<re<<endl;
		while(o.size()<re){
			o+=t.back();
			o+=t.back();
			t.pop_back();
		}
		int len=n/re/2;
		rep(i,re) out(t.substr(len*i,len),string(1,o[i]));
	}else{
		cout<<1<<endl;
		out(t,"");
	}
	
}