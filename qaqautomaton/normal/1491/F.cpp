/*
Author: QAQAutoMaton
Lang: C++
Code: F.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(qaq...) fprintf(stderr,qaq)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
#define unq(a) sort(all(a)),a.erase(unique(all(a)),a.end())
using namespace std;
typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cp;
typedef pair<int,int> pii;
int inf;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T,class T2>int chkmin(T &a,T2 b){return a>b?a=b,1:0;}
template<class T,class T2>int chkmax(T &a,T2 b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T,class T2>T mmin(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T mmax(T a,T2 b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
template<class T>bool sort2(T &a,T &b){return a>b?swap(a,b),1:0;}
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		fill((unsigned char*)&inf,(unsigned char*)&inf+sizeof(inf),0x3f);
	}
}__INIT___;
int _i[2005];
int ask(vector<int> a,vector<int> b){
	cout<<"? "<<a.size()<<' '<<b.size()<<endl;
	for(auto i:a)cout<<i<<' ';cout<<endl;
	for(auto i:b)cout<<i<<' ';cout<<endl;
	int w;
	cin>>w;
	return w;
}
vector<int> range(int l,int r){
	return vector<int> (_i+l,_i+r+1);
}
bool answer(vector<int> ans){
	cout<<"! "<<ans.size();
	for(auto i:ans)cout<<' '<<i;
	cout<<endl;
	return 0;
}
namespace run{
	vector<int> ans;
	bool main(){
		int n;	
		cin>>n;
		ans.clear();
		for(int i=1;i<=n;++i)_i[i]=i;
		for(int i=2;i<=n;++i){
			if(ask({i},range(1,i-1))){
				int l=1,r=i-1;
				while(l<r){
					int mid=(l+r)>>1;
					if(ask({i},range(l,mid)))r=mid;
					else l=mid+1;
				}
				for(int j=1;j<i;++j)if(j!=l)ans.emplace_back(j);
				for(int j=i+1;j<=n;++j)if(!ask({i},{j}))ans.emplace_back(j);
				return answer(ans);
			}
		}
		assert(0);
		return 0;
	}
}
signed main(){
	int t;
	cin>>t;
	for(;t;--t){
		run::main();
	}
	return 0;
}