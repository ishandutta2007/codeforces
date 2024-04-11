#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)

#define rep2(i,a,b) for(int64_t i=a;i <= (int64_t)(b);i++)
#define FILE_IN "tree.inp"
#define FILE_OUT "tree.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define pow2(x) (ll(1)<<x)
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define endl "\n"
#define finish(s) {cout<<s;return 0;}
int n,sz,all,len[12],now[12];
string ch,tmp,s[12][10005];
 
int main()
{
	cin>>n;
	rep2(i,1,n)
	{
		cin>>tmp;sz=tmp.size();
		all+=sz;s[sz][++len[sz]]=tmp;
	}
	cin>>ch;all/=(n/2);
	rep2(i,1,10) if (len[i]) sort(s[i]+1,s[i]+len[i]+1);
	rep2(i,1,n/2)
	{
		int who=0;string ss="";
		rep2(j,1,10) if (now[j]<len[j])
		  if (!who||s[j][now[j]+1]+ch+s[all-j][now[all-j]+1+(all-j==j)]<ss)
		    who=j,ss=s[j][now[j]+1]+ch+s[all-j][now[all-j]+1+(all-j==j)];
		now[who]++;now[all-who]++;cout<<ss<<endl;
	}
	return 0;
}