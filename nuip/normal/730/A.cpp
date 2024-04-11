#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	if(n==2){
		if(a[0]==a[1]){
			cout<<a[0]<<endl<<0<<endl;
		}else{
			cout<<0<<endl<<max(a[0],a[1])<<endl;
			rep(i,max(a[0],a[1])) cout<<"11"<<endl;
		}
		return 0;
	}
	int mn=*min_element(all(a));
	int mx=*max_element(all(a));
	int sum=accumulate(all(a),0);
	sum-=mn*n; mx-=mn;
	int t=0;
	//cout<<mn<<","<<mx<<","<<sum<<endl;
	while(mx*2>sum){ sum+=n; ++t; ++mx;}
	priority_queue<pii> que;
	rep(i,n){
		int tmp=a[i]-mn+t;
		//cout<<tmp<<endl;
		if(tmp) que.emplace(tmp,i);
	}
	//cout<<t<<endl;
	vector<string> re;
	while(que.size()>1){
		string s(n,'0');
		pii a=que.top(); que.pop();
		pii b=que.top(); que.pop();
		//cout<<a.X<<":"<<a.Y<<","<<b.X<<":"<<b.Y<<endl;
		s[a.Y]=s[b.Y]='1';
		re.pb(s);
		if(a.X>1) que.emplace(a.X-1,a.Y);
		if(b.X>1) que.emplace(b.X-1,b.Y);
	}
	if(que.size()){
		assert(que.top().X==1);
		rep(i,re.size()) if(re[i][que.top().Y]=='0'){
			re[i][que.top().Y]='1';
			break;
		}
	}
	cout<<max(0,mn-t)<<endl;
	cout<<re.size()<<endl;
	for(string s:re) cout<<s<<endl;
	return 0;
}