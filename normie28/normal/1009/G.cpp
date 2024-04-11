
// Problem : E. Magical Permutation
// Contest : Codeforces - Codeforces Round #558 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1163/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
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
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int N=1e5+5;
char s[N];
int cnt[1<<7];
int match[N];
int need[1<<7];
int n,m;
bool judge(){
	for(int i=0;i<64;i++){
		if(need[i]<cnt[i])return 0;
	}
	return 1;
}
void remove(int pos,int ch){
	for(int mask=0;mask<64;mask++){
		if(mask&(1<<ch)){
			cnt[mask]--;
		}
		if(mask&match[pos]){
			need[mask]--;
		}
	}
}
void add(int pos,int ch){
	for(int mask=0;mask<64;mask++){
		if(mask&(1<<ch)){
			cnt[mask]++;
		}
		if(mask&match[pos]){
			need[mask]++;
		}
	}
}
int ans[N];
int main(){
	cin>>s;
	n=strlen(s);
	for(int i=0;i<n;i++){
		cnt[1<<(s[i]-'a')]++;
	}
	for(int mask=1;mask<64;mask++){
		for(int sub=1;sub<mask;sub++){
			if((sub&mask)==sub){
				cnt[mask]=cnt[sub]+cnt[mask^sub];
			}
		}
	}
	for(int i=1;i<=n;i++){
		match[i]=63;
	}
	cin>>m;
	int p;
	char str[10];
	for(int i=1;i<=m;i++){
		scanf("%d%s",&p,str);
		int l=strlen(str);
		int mask=0;
		for(int j=0;j<l;j++){
			mask|=1<<(str[j]-'a');
		}
		match[p]&=mask;
	}
	for(int mask=0;mask<64;mask++){
		for(int i=1;i<=n;i++){
			if(mask&match[i]){
				need[mask]++;
			}
		}
	}
	if(!judge()){
		cout<<"Impossible"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<6;j++){
			if(match[i]&(1<<j)){
				remove(i,j);
				if(judge()){
					ans[i]=j;
					break;
				}
				else{
					add(i,j);
				}
			}
		}
	}	
	for(int i=1;i<=n;i++){
		cout<<(char)(ans[i]+'a');
	}
}