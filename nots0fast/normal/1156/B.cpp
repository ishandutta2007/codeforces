#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX 400010
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = pow(10,9)+7;

bool good(vector<int>& a){
	fori((int)a.size() - 1)
		if(fabs(a[i]-a[i+1])==1)
			return 0;
	return 1;
}

void deal(){
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		int num[26];
		fori(26)
			num[i] = 0;
		fori(a.length())
			num[a[i]-'a']++;
		vector<int> ans, ans1;
		for(int i=24; i>-1; i-=2)
			if(num[i])
				ans.pb(i);
		for(int i=25; i>-1; i-=2)	
			if(num[i])
				ans.pb(i), ans1.pb(i);
		for(int i=24; i>-1; i-=2)
			if(num[i])
				ans1.pb(i);
		bool gg = 1;
		if(!good(ans)){
			int hd = ans[ans.size()-1];
			ans.erase(ans.end()-1);
			ans.insert(ans.begin(), hd);
			if(!good(ans))
				gg = 0;
		}
		if(!gg){
			gg = 1;
			ans = ans1;
			if(!good(ans)){
				int hd = ans[ans.size()-1];
				ans.erase(ans.end()-1);
				ans.insert(ans.begin(), hd);
				if(!good(ans))
					gg = 0;
			}
			if(!gg)
				cout<<"No answer"<<endl;
		}	
		if(gg){
			fori(ans.size()){
				forj(num[ans[i]])
					cout<<(char)('a'+ans[i]);
			}
			cout<<endl;
		}
	}
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}