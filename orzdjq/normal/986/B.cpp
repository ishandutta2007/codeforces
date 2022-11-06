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
const int Maxn=1000005;
int a[Maxn],b[Maxn];
int pos[Maxn];
int main(){
	//freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) a[i]=i,b[i]=read(),pos[i]=i;
	int cnt=0;
	for (int i=n;i>=1;i--){
		if (a[i]!=b[i]){
			pos[a[i]]=pos[b[i]];
			//cout<<i<<' '<<a[i]<<' '<<b[i]<<endl;
			pos[b[i]]=i;
			swap(a[pos[a[i]]],a[i]);
			cnt++;
		}
	//	for (int j=1;j<=n;j++) cout<<pos[j]<<' ';
	//	cout<<endl;
	}
//	cout<<cnt<<endl;
	int x=n*3,y=n*7-1;
	if ((x&1)==(cnt&1)){
		printf("Petr\n");
	}
	else{
		printf("Um_nik\n");
	}
	return 0;
}