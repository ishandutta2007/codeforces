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
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
int n;
string s, t;
 
int main(){
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	cin >> s >> t;
	
	int x = 0; while(x < n && s[x] == t[x]) x++;
	if(x == n){cout << n*('z'-'a') + 'z'-'a'+1 << endl; return 0;}
	
	int ans = 0;
	
	int i = x;
	int j = x+1;
	while(j < n && i < n){
		if(s[i] == t[j]){i++; j++;}
		else i++;
	}
	if(j == n) ans++;
	
	i = x;
	j = x+1;
	while(j < n && i < n){
		if(s[j] == t[i]){i++; j++;}
		else i++;
	}
	if(j == n) ans++;
	
	cout << ans << endl;
}