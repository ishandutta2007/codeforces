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
template<class T,class ...T2>T mmin(T a,T2 ...b){return mmin(a,mmin(b...));}
template<class T,class ...T2>T mmax(T a,T2 ...b){return mmax(a,mmax(b...));}
#define min mmin
#define max mmax
#define abs aabs
namespace run{
	int d[1005];
	int in[1005];
	int id[1005],col[1005];
	vector<int> to[1005];
	int query(int x){
		cout<<"? "<<x<<endl;
		int y;
		cin>>y;
		return y;
	}
	void dfs(int x,int c){
		if(col[x])return;
		col[x]=c;
		for(auto i:to[x])dfs(i,c);
	}
	bool main(){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>d[i];
			id[i]=i;
			in[i]=0;
			to[i].clear();
			col[i]=0;
		}
		sort(id+1,id+n+1,[](int x,int y){return d[x]>d[y];});
		for(int i=1;i<=n;++i){
			int x=id[i];
			for(int j=1;j<=d[x] && !in[x];++j){
				int v=query(x);
				to[x].emplace_back(v);
				to[v].emplace_back(x);
				if(in[v]){in[x]=1;}
				else in[v]=1;
			}
			in[x]=1;
		}
		int c=0;
		for(int i=1;i<=n;++i)if(!col[i]){
			dfs(i,++c);
		}
		cout<<"!";
		for(int i=1;i<=n;++i)cout<<' '<<col[i];
		cout<<endl;
		return 0;
	}
}
signed main(){
	int t;
	cin>>t;
	for(;t;--t)run::main();
	return 0;
}