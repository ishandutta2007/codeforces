#include<cmath>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#define LL long long
#define ll long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int Maxn=10005;
int n,q;
vector<int> tag[Maxn*4];
void modify(int p,int l,int r,int lo,int hi,int val){
	if (lo<=l && r<=hi){
		tag[p].pb(val);
		return;
	}
	int mid=l+r>>1;
	if (lo<=mid){
		modify(p*2,l,mid,lo,min(hi,mid),val);
	}
	if(hi>mid){
		modify(p*2+1,mid+1,r,max(lo,mid+1),hi,val);
	}
}
bitset<10001> ans;
void Go(int p,int l,int r,bitset<10001> X){
	for (int i=0;i<tag[p].size();i++){
		X|=X<<tag[p][i];
	}
	ans|=X; 
	if (l==r) return;	
	int mid=l+r>>1;
	Go(p*2,l,mid,X);
	Go(p*2+1,mid+1,r,X);
}
int main(){
	n=read();q=read();
	for (int i=0;i<q;i++){
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		modify(1,1,n,l,r,x);
	}
	bitset<10001> tmp;
	tmp[0]=1;
	ans[0]=1;
	Go(1,1,n,tmp);
	vector<int> res;
	for (int i=1;i<=n;i++){
		if (ans[i]){
			res.pb(i);
		}
	}
	printf("%d\n",res.size());
	for (int i=0;i<res.size();i++){
		printf("%d ",res[i]);
	}
	printf("\n");
	return 0;
}