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
const int Maxn=200005;
int n;
LL L;
LL a[Maxn*2],b[Maxn*4];
int lo[Maxn*2],hi[Maxn*2];
int X[Maxn*2],Y[Maxn*2];
int Xa[Maxn*2],Ya[Maxn*2];
int Xb[Maxn*2],Yb[Maxn*2];
bool check(int D){
	lo[0]=hi[0]=1;
	for (int i=1;i<=2*n;i++){
		lo[i]=lo[i-1];
		hi[i]=hi[i-1];
		while (a[i]>=b[lo[i]] && abs(a[i]-b[lo[i]])>D){
			lo[i]++;
		}
		//while (a[i]>=b[hi[i]]) hi[i]++;
		while (b[hi[i]]-a[i]<=D) hi[i]++;
		//cout<<i<<' '<<lo[i]<<' '<<hi[i]<<' '<<b[lo[i]]<<' '<<b[hi[i]-1]<<endl;
		if (i!=1 && lo[i]>hi[i-1]) return false;
	}
	for (int i=1;i<=2*n;i++){
		X[i]=lo[i]-i;
		hi[i]--;
		Y[i]=hi[i]-i;
	}
	Xa[1]=X[1];Xa[1+n]=X[1+n];
	Ya[1]=Y[1];Ya[1+n]=Y[1+n];
	for (int i=2;i<=n;i++){
		Xa[i+n]=max(Xa[i+n-1],X[i+n]);
		Xa[i]=max(Xa[i-1],X[i]);
		Ya[i+n]=min(Ya[i+n-1],Y[i+n]);
		Ya[i]=min(Ya[i-1],Y[i]);
	}
	Xb[n]=X[n];Xb[n+n]=X[n+n];
	Yb[n]=Y[n];Yb[n+n]=Y[n+n];
	for (int i=n-1;i>=1;i--){
		Xb[i+n]=max(Xb[i+n+1],X[i+n]);
		Xb[i]=max(Xa[i+1],X[i]);
		Yb[i+n]=min(Yb[i+n+1],Y[i+n]);
		Yb[i]=min(Yb[i+1],Y[i]);
	}
	for (int i=1;i<=n;i++){
		int zz=X[i];
		int YY=min(Yb[i],Ya[i+n]);
		if (YY<zz)  return false;
	}
	return true;
}
int main(){
	scanf("%d %I64d",&n,&L);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		a[n+i]=a[i]+L;
	}
	sort(a+1,a+1+n+n);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&b[i]);
		b[i]=b[i]-L;
		b[i+n]=b[i]+L;
		b[i+n+n]=b[i]+L+L;
		b[i+n+n+n]=b[i]+L+L+L;
	}
	
	sort(b+1,b+1+n+n+n+n);
	int lo=-1,hi=L/2;
	//check(13);
	//return 0;
	while (hi-lo>1){
		int mid=lo+hi>>1;
		if (check(mid)){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	printf("%d\n",hi);
}