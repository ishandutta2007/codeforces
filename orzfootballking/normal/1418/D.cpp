/*

DP





ll int
 dp 










*/
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
int p[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	multiset<int> s1,s2;
	cin>>n>>q;
	FOR(i,1,n){
		cin>>p[i];
		s1.emplace(p[i]);
	}
	sort(p+1,p+n+1);
	FOR(i,2,n){
		s2.emplace(-(p[i]-p[i-1]));
	}
	int back,begin;
	auto it=s1.end();
	it--;
	back=*it;
	begin=*s1.begin();
	cout<<back-begin+(*s2.begin())<<'\n';
	FOR(i,1,q){
		bool f;
		int x;
		cin>>f>>x;
		if(f){
			s1.emplace(x);
			auto it=s1.find(x),e=s1.end();e--;
			if(it!=s1.begin()&&it!=e){
				int t;
				it++;
				t=*it;
				it--;it--;
				t-=*it;
				s2.erase(s2.find(-t));
				it++;
			}
			if(it!=s1.begin()){
				int t=*it;
				it--;
				t-=*it;
				s2.insert(-t);
				it++;
			}
			if(it!=e){
				int t;
				it++;
				t=*it;
				it--;
				t-=*it;
				s2.insert(-t);
			}
		}else{
			auto it=s1.find(x),e=s1.end();e--;
			if(it!=s1.begin()&&it!=e){
				int t;
				it++;
				t=*it;
				it--;it--;
				t-=*it;
				s2.insert(-t);
				it++;
			}
			if(it!=s1.begin()){
				int t=*it;
				it--;
				t-=*it;
				s2.erase(s2.find(-t));
				it++;
			}
			if(it!=e){
				int t;
				it++;
				t=*it;
				it--;
				t-=*it;
				s2.erase(s2.find(-t));
			}
			s1.erase(x);
		}
		if(!s1.size()||s1.size()==1){
			cout<<0<<'\n';continue;
		}
		it=s1.end();
		it--;
		back=*it;
		begin=*s1.begin();
		cout<<back-begin+(*s2.begin())<<'\n';
	}
	RE 0;
}