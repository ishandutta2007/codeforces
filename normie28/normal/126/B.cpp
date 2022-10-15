#include <bits/stdc++.h>
/***********MACROS***************/
#define int long long 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
 
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define endl "\n"
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
const int maxn = 1000010;
const ll values[12]={0,5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[30001][12]; ll n,i,j;
long double c;
string res;
/*********FUNCTIONS**************/
string s;
int zf[maxn];
 
/***********MAIN**************/
 
signed main(){ 
    fio;
	cin >> s;
	int l = 0 , r = 0;
	for(int i=1;i<(int)s.size();i++) {
		if(i > r) {
			l = r = i;
			while(r < (int)s.size() && s[r] == s[r-l])	r++;
			r--;
			zf[i] = r-l+1;
		}
		else {
			int k = i-l;
			if(i + zf[k] - 1 < r)
				zf[i] = zf[k];
			else {
				l = i;
				while(r < (int)s.size() && s[r] == s[r-l])	r++;
				r--;
				zf[i] = r-l+1;
			}
		}
	}
	int max_len = 0;
	for(int i=1;i<(int)s.size()-1;i++) {
		int len = zf[i];
		if(i + len - 1 == (int)s.size()-1)
			len--;
		max_len = max(max_len,len);
	}
	int ans = -1;
	for(int i=1;i<(int)s.size();i++)
		if(i + zf[i] - 1 == (int)s.size() - 1 && zf[i] <= max_len)
			ans = max(ans,zf[i]);
	if(ans==-1)	
		cout << "Just a legend" << "\n";
	else
		cout << s.substr(0,ans) << "\n";
}