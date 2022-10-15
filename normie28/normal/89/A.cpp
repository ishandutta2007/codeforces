#include<bits/stdc++.h>
using namespace std;
#define FILE_IN "pviz.in"
#define FILE_OUT "pviz.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define boring_mod 10007
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define endl "\n"

ll n,b,i,j,m,c,d,k,t,t1,x,y,cup[101000],a[350],upd[350],mn[350],cnt[350],l[101000],r[101000];
vector<int> gt[101000],check;
vector<piii> event;
vector<pii> cd[350];
int main() {
	int aa;
//	ofile;
	fio;
	cin>>n>>m>>k;
	if (n%2==0)
	{
		cout<<0;
		return 0;
	}
	j=1e9;
	for (i=0;i<n;i++) cin>>cup[i];
	for (i=0;i<n;i+=2) j=min(j,cup[i]);
	c=n/2+1;
	cout<<min(j,(m/c)*k);
}