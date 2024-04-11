#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)

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
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,m,i,j,k,t[200],cnt,p,nodes=1,fail=0;
int dp[1<<15],e[20],l[10000],r[10000],d[10000];
int main(){
	fio;
	cin>>n;
	int a,b,c;
	for (i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		cnt=0;
		if ((a)) {a--; cnt++;}
		if ((b)) {b--; cnt++;}
		if ((c)) {c--; cnt++;}
		if ((a>=b)and(a>=c))
		{
			if ((a)and(b)) {cnt++; a--; b--;}
			if ((a)and(c)) {cnt++; a--; c--;}
			if ((c)and(b)) {cnt++; c--; b--;}
			if ((c)and(b)and(a)) {cnt++; c--; b--; a--;}
			cout<<cnt<<endl;
		}
		else if ((b>=a)and(b>=c))
		{
			if ((a)and(b)) {cnt++; a--; b--;}
			if ((c)and(b)) {cnt++; c--; b--;}
			if ((a)and(c)) {cnt++; a--; c--;}
			if ((c)and(b)and(a)) {cnt++; c--; b--; a--;}
			cout<<cnt<<endl;
		}
		else if ((c>=a)and(c>=b))
		{
			if ((a)and(c)) {cnt++; a--; c--;}
			if ((c)and(b)) {cnt++; c--; b--;}
			if ((a)and(b)) {cnt++; a--; b--;}
			if ((c)and(b)and(a)) {cnt++; c--; b--; a--;}
			cout<<cnt<<endl;
		}
	}
}