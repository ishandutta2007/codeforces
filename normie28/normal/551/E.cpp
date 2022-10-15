
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
const int N=5e5 , N2=1e1;
ll s[N] , sum[N];
vector<pair<ll , int>>lol[N];
int main (){
	fio;
	int n ,q , root; cin>>n>>q;
	root=sqrt(n)+1;
	for(int i=0 ; i<n ; i++){
	    cin>>s[i];
	     lol[i/root].push_back(make_pair(s[i] , i));
	}
	for(int i=0 ; i<=root ; i++)sort(lol[i].begin() , lol[i].end());
	for(int i=0 ; i<q ; i++){
		int p;cin>>p;
		if(p==1){
			int l , r , o1=-1 , o2=-1; ll x;
			cin>>l>>r>>x; l--;r--;
			for(int i2=l ;i2<=r ; i2++){
				if(i2%root==0 && i2+root-1<=r){sum[i2/root]+=x;i2+=root-1;}
				else{
					s[i2]+=x;
					if(o1==-1)o1=i2/root;
					else if(o1!=i2/root && o2==-1)o2=i2/root;
				}
			}
			if(~o1){
				lol[o1].clear();
				for(int i2=o1*root ; i2<(o1+1)*root && i2<n; i2++)lol[o1].push_back(make_pair(s[i2] , i2));
				sort(lol[o1].begin() , lol[o1].end());
			}
			if(~o2){
				lol[o2].clear();
				for(int i2=o2*root ; i2<(o2+1)*root && i2<n  ; i2++)lol[o2].push_back(make_pair(s[i2] , i2));
				sort(lol[o2].begin() , lol[o2].end());
			}
		}
		else{
			ll x ; cin>>x;
			int mn=5e5 , mx=-1;
			for(int i2=0 ; i2<n ; i2+=root){
				int k=lower_bound(lol[i2/root].begin() , lol[i2/root].end() , make_pair(x-sum[i2/root], -1))-lol[i2/root].begin();
				if(k==lol[i2/root].size()||lol[i2/root][k].first!=x-sum[i2/root])continue;
				mn=min(mn , lol[i2/root][k].second);
				k=lower_bound(lol[i2/root].begin() , lol[i2/root].end() , make_pair(x-sum[i2/root]+1 , -1))-lol[i2/root].begin();
				k--;
				mx=max(mx , lol[i2/root][k].second);
			}
			if(mx==-1) cout<<-1<<endl;
			else cout<<mx-mn<<endl;
		}
	}
}