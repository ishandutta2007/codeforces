/*
Author: QAQAutomaton
Lang: C++
Code: kaguya.cpp
Mail: lk@qaq-am.com
Blog: https://www.qaq-am.com/
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
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
#define min mmin
#define max mmax
#define abs aabs
struct __INIT__{
	__INIT__(){
		memset(&inf,0x3f,sizeof(inf));
	}
}__INIT___;
int n;
int nx[4][4];
int w[55];
int od[4],id[4];
char s[]={" CHO"};
bool ask(const vector<int>&vt){
	cout<<"? ";
	for(auto i:vt)cout<<s[i];
	cout<<endl;
	int k;
	cin>>k;
	if(!~k)exit(0);
	if(!k)return 0;
	int m=vt.size();
	for(;k;--k){
		int x;
		cin>>x;
		for(int i=0;i<m;++i)w[i+x]=vt[i];
	}
	return 1;
} 
bool find(){
	int s=-1,at=0;
	for(int i=1;i<=n;++i)if(w[i]){
		if(i>1&&id[w[i]]==1){
			for(int j=1;j<=3;++j)if(nx[j][w[i]]){w[i-1]=j;return 1;}
		}
		int j=i;
		while(w[j+1])++j;
		if(j<n&&od[w[j]]==1){
			for(int k=1;k<=3;++k)if(nx[w[j]][k]){w[j+1]=k;return 1;}
		}
		if(chkmax(s,j-i))at=i;
		i=j;
	}
	if(s==n-1)return 0;
	int wi=at==1?inf:id[w[at]],wo=at+s==n?inf:od[w[at+s]]-(at+s==n-1||od[1]?0:1);
	if(wi<=wo){
		vector<int> q(s+2);
		for(int i=0;i<=s;++i)q[i+1]=w[i+at];
		int c=id[w[at]];
		for(int i=1;i<=3;++i)if(nx[i][w[at]]){
			if(c>1){
				q[0]=i;
				if(ask(q))return 1;
				--c;
			}
			else {w[at-1]=i;return 1;}
		}
	}
	else{
		vector<int> q(s+2);
		for(int i=0;i<=s;++i)q[i]=w[i+at];
		int c=wo;
		for(int i=1;i<=3;++i)if(nx[w[at+s]][i]&&(i!=1||at+s==n-1||od[1])){
			if(c>1){
				q[s+1]=i;
				if(ask(q))return 1;
				--c;
			}
			else {w[at+s+1]=i;return 1;}
		}
	}
	return 0;
}
bool try2(int x,int y){
	if(ask({x,y})){nx[x][y]=0;--od[x];--id[y];while(find()){}return 1;}
	else {nx[x][y]=0;--od[x];--id[y];return 0;}
}
bool gg(){
	vector<int>v(n-1,2);
	if(ask(v))return find(),1;
	for(auto &i:v)i=3;
	v.emplace_back(1);
	if(ask(v))return 1;
	for(int i=1;i<=n;++i)w[i]=3;
	return 1;
}
void answer(){
	cout<<"! ";
	for(int i=1;i<=n;++i)cout<<s[w[i]];
	cout<<endl;
	int k;
	cin>>k;
	if(!~k)exit(0);
	for(int i=1;i<=n;++i)w[i]=0;
}
bool gg4(){
	if(ask({2,3,3})){
		if(ask({2,3,3,3}))return 1;
		if(ask({2,2,3,3}))return 1;
		w[1]=2;w[2]=3;w[3]=3;w[4]=1;
		return 1;
	}
	if(ask({2,2,2})){
		if(ask({2,2,2,1}))return 1;
		if(ask({2,2,2,2}))return 1;
		w[1]=2;w[2]=2;w[3]=2;w[4]=3;
		return 1;
	}
	return ask({2,2,3,1})||ask({3,3,3,3})||(w[1]=w[2]=w[3]=3,w[4]=1);
}
void query(){
	for(int i=1;i<=3;++i)for(int j=1;j<=3;++j)nx[i][j]=1;
	for(int i=1;i<=3;++i)od[i]=id[i]=3;
	if(n==4)try2(1,1)||try2(1,2)||try2(1,3)||try2(3,2)||gg4();
	else try2(1,1)||try2(1,2)||try2(1,3)||try2(2,3)||try2(3,2)||gg();
	answer();
}
signed main(){
	int t;
	cin>>t;
	for(;t;--t){
		cin>>n;
		query();
	}
	return 0;
}