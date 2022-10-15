
// Problem : E. Expression
// Contest : Codeforces - Codeforces Beta Round #54 (Div. 2)
// URL : https://codeforces.com/problemset/problem/58/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//----------NMFF0B0H----------//
#include <bits/stdc++.h>
#define IM using
#define GAY namespace
#define LOL std;
IM GAY LOL
/*
Search the term 'algorithm visualization' in your favorite Search Engine, do you see VisuAlgo in the first page of the search result :)? Next level: Search that term again, but in your native language (if it is not English). Is VisuAlgo still listed in the first page? :). And get ready to be surprised: Search the name of your favorite data structure or algorithm without mentioning the keyword 'animation' or 'visualization'. Is VisuAlgo still listed in the first page? :):).
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define FILE_IN "caps.inp"
#define FILE_OUT "caps.out"
#define ofile                     \
    freopen(FILE_IN, "r", stdin); \
    freopen(FILE_OUT, "w", stdout)
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define nfio    \
    cin.tie(0); \
    cout.tie(0)
#define ord(a, b, c) ((a >= b) and (b >= c))
#define MOD (ll(18101203))
#define INF 1e18;
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1) << x)
#define pii pair<int, int>
#define piii pair<int, pii>
#define For(i, __, ___) for (int i = __; i <= ___; i++)
#define Rep(i, __, ___) for (int i = __; i >= ___; i--)
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define vi vector<int>
#define bi bigint
#define get geet
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
#define int long long
//--------END----------//
int dp[21][21][21][2];
string sa[21][21][21][2];
string sb[21][21][21][2];
string a,b,c;
void top_down(int i,int j,int k,bool l) {
	if (!i&&!j&&!k&&!l) return;
	int imin1=i-1,jmin1=j-1,kmin1=k-1;
	if (imin1<0) imin1=0; if (jmin1<0) jmin1=0; if (kmin1<0) kmin1=0;
	bool addi;
	if (!k) addi=true;
	else addi=false;
	if (a[i]-'0'+b[j]-'0'+l==c[k]-'0') {
		if (dp[i][j][k][l]+addi<dp[imin1][jmin1][kmin1][0]) {
			dp[imin1][jmin1][kmin1][0]=dp[i][j][k][l]+addi;
			sa[imin1][jmin1][kmin1][0]=a[i]+sa[i][j][k][l];
			sb[imin1][jmin1][kmin1][0]=b[j]+sb[i][j][k][l];
			top_down(imin1,jmin1,kmin1,0);
		}
	} else if (a[i]-'0'+b[j]-'0'+l==c[k]-'0'+10) {
		if (dp[i][j][k][l]+addi<dp[imin1][jmin1][kmin1][1]) {
			dp[imin1][jmin1][kmin1][1]=dp[i][j][k][l]+addi;
			sa[imin1][jmin1][kmin1][1]=a[i]+sa[i][j][k][l];
			sb[imin1][jmin1][kmin1][1]=b[j]+sb[i][j][k][l];
			top_down(imin1,jmin1,kmin1,1);
		}
	} else {
		int d=(c[k]-b[j]-l+10)%10;
		if (d+b[j]-'0'+l==c[k]-'0') {
			if (dp[i][j][k][l]+1+addi<dp[i][jmin1][kmin1][0]) {
				dp[i][jmin1][kmin1][0]=dp[i][j][k][l]+1+addi;
				sa[i][jmin1][kmin1][0]=char(d+'0')+sa[i][j][k][l];
				sb[i][jmin1][kmin1][0]=b[j]+sb[i][j][k][l];
				top_down(i,jmin1,kmin1,0);
			}
		} else if (d+b[j]-'0'+l==c[k]-'0'+10) {
			if (dp[i][j][k][l]+1+addi<dp[i][jmin1][kmin1][1]) {
				dp[i][jmin1][kmin1][1]=dp[i][j][k][l]+1+addi;
				sa[i][jmin1][kmin1][1]=char(d+'0')+sa[i][j][k][l];
				sb[i][jmin1][kmin1][1]=b[j]+sb[i][j][k][l];
				top_down(i,jmin1,kmin1,1);
			}
		}
		d=(c[k]-a[i]-l+10)%10;
		if (a[i]-'0'+d+l==c[k]-'0') {
			if (dp[i][j][k][l]+1+addi<dp[imin1][j][kmin1][0]) {
				dp[imin1][j][kmin1][0]=dp[i][j][k][l]+1+addi;
				sa[imin1][j][kmin1][0]=a[i]+sa[i][j][k][l];
				sb[imin1][j][kmin1][0]=char(d+'0')+sb[i][j][k][l];
				top_down(imin1,j,kmin1,0);
			}
		} else if (a[i]-'0'+d+l==c[k]-'0'+10) {
			if (dp[i][j][k][l]+1+addi<dp[imin1][j][kmin1][1]) {
				dp[imin1][j][kmin1][1]=dp[i][j][k][l]+1+addi;
				sa[imin1][j][kmin1][1]=a[i]+sa[i][j][k][l];
				sb[imin1][j][kmin1][1]=char(d+'0')+sb[i][j][k][l];
				top_down(imin1,j,kmin1,1);
			}
		}
		d=(a[i]-'0'+b[j]-'0'+l+10)%10;
		if (a[i]-'0'+b[j]-'0'+l==d) {
			if (dp[i][j][k][l]+1<dp[imin1][jmin1][k][0]) {
				dp[imin1][jmin1][k][0]=dp[i][j][k][l]+1;
				sa[imin1][jmin1][k][0]=a[i]+sa[i][j][k][l];
				sb[imin1][jmin1][k][0]=b[j]+sb[i][j][k][l];
				top_down(imin1,jmin1,k,0);
			}
		} else if (a[i]-'0'+b[j]-'0'+l==d+10) {
			if (dp[i][j][k][l]+1<dp[imin1][jmin1][k][1]) {
				dp[imin1][jmin1][k][1]=dp[i][j][k][l]+1;
				sa[imin1][jmin1][k][1]=a[i]+sa[i][j][k][l];
				sb[imin1][jmin1][k][1]=b[j]+sb[i][j][k][l];
				top_down(imin1,jmin1,k,1);
			}
		}
	}
}
signed main() {
	fio;
	string s;
	int tempa,tempb,tempc;
	char temp;
	getline(cin,s);
	stringstream ss;
	ss<<s;
	ss>>tempa>>temp>>tempb>>temp>>tempc;
	a=to_string(tempa); b=to_string(tempb); c=to_string(tempc);
	a="0"+a; b="0"+b; c="0"+c;
	for (int i=0;i<21;i++) for (int j=0;j<21;j++)
	for (int k=0;k<21;k++) dp[i][j][k][0]=dp[i][j][k][1]=INF;
	dp[a.length()-1][b.length()-1][c.length()-1][0]=0;
	top_down(a.length()-1,b.length()-1,c.length()-1,0);
	int resa=stoll(sa[0][0][0][0]);
	int resb=stoll(sb[0][0][0][0]);
	cout<<resa<<"+"<<resb<<"="<<resa+resb;
}