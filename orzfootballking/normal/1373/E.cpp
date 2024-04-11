#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int cnt(int p){
	int sum=0;
	while(p){
		sum+=p%10;
		p/=10;
	}
	RE sum;
}
int l,x;
string print(int fro,int fr){
	string s;
	while(fro){
		if(fro<9){
			s+=(char)(fro+'0');break;
		}else {
			s+='9';fro-=9;
		}
	}
	if(s.size()==0){
		stringstream ss;
		ss<<fr;
		string re;
		ss>>re;
		RE re;
	}
	reverse(ALL(s));
	stringstream ss;
	ss<<fr;
	string sl,sr;
	ss>>sl;
	ss.clear();
	ss<<(fr+l-1);
	ss>>sr;
	while(sl.size()<sr.size())sl='0'+sr;
	RE s+sl;
}
void check(string &s,string t){
	if(s=="-1"){
		s=t;
	}else if(s.size()>t.size()||(s.size()==t.size()&&s>t)){
		s=t;
	}
}
void solve(){
	cin>>x>>l;l++;
	int sum=0;
	rep(i,0,l)sum+=cnt(i);
	if(sum>x){
		cout<<"-1\n";RE;
	}
	string ans="-1";
	if((x-sum)%l==0){
		check(ans,print((x-sum)/l,0));
	}
	FOR(r,l,2000){
		sum+=cnt(r);
		sum-=cnt(r-l);
		if((x-sum)%l==0&&x>=sum){
			check(ans,print((x-sum)/l,r-l+1));
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)solve();
	RE 0;
}