// Problem : D. DZY Loves Strings
// Contest : Codeforces - Codeforces Round #254 (Div. 1)
// URL : https://codeforces.com/contest/444/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define pb push_back
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
const ll N = 1e6+6,B = 31;
vector<ll>vec[N];
map<ll,ll>Res[N];
ll getHash( string s )
{
    ll ret = 0,i = 0;
    while(i<s.size())
        ret = (31*ret)+(s[i++]-'a')+1;
    return ret;
}
 
int main()
{
    fio;
    string s;cin>>s;
    ll sz = s.size();
    for(ll i=0;i<sz;i++)
    {
        ll j = 0,now = 0;
        while(j<4&&i+j<sz)
        {
            now = (31*now) + (s[i+(j++)]-'a'+1);
            vec[now].pb(i);
        }
    }
    ll q;cin>>q;
    while(q--)
    {
        string s1,s2;cin>>s1>>s2;
        int h1 = getHash(s1);
        int h2 = getHash(s2);
        int l1 = s1.size(),l2 = s2.size();
        if( Res[h1][h2] )
            cout<<Res[h1][h2]<< "\n";
        else if( Res[h2][h1] )
            cout<<Res[h2][h1]<< "\n";
        else
        {
            if( !vec[h1].size()||!vec[h2].size() )
            {
                cout<< "-1\n";
                continue;
            }
            int a = 0,b = 0,ret = 1e9;
            while(a<vec[h1].size()&&b<vec[h2].size())
            {
                ret = min(ret,max(vec[h1][a]+l1,vec[h2][b]+l2)-min(vec[h1][a],vec[h2][b]));
                if( vec[h1][a]<vec[h2][b] )a++;
                else b++;
            }
            Res[h1][h2] = ret;
            cout<<ret<< "\n";
        }
    }
}