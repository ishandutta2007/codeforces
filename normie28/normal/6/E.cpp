/*
 A Submission by NMFF0B0H
 at time: 2020-03-21 16:08:56
*/
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
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define oset tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n,m,k,c[100001],i,j,l;
vi calc(int x)
{
    int low[100001],hi[100001];
    vector<int> res; deque<int> st;
    int i;
    for (i=0;i<n;i++)
    {
        while ((st.size())and(st.back()>c[i])) st.pop_back();
        st.push_back(c[i]);
        if ((i>x-1)and(st.front()==c[i-x])) st.pop_front();
        if (i>=x-1) low[i]=st.front();
    }
    st.clear();
    for (i=0;i<n;i++)
    {
        while ((st.size())and(st.back()<c[i])) st.pop_back();
        st.push_back(c[i]);
        if ((i>x-1)and(st.front()==c[i-x])) st.pop_front();
        if (i>=x-1) hi[i]=st.front();
    }
    for (i=x-1;i<n;i++) {//cout<<hi[i]<<' '<<low[i]<<endl;
     if (hi[i]-low[i]<=k) res.push_back(i);}
    return res;
}
pair<int,vi> bs(int l, int r)
{
    if (l==r) return {l,calc(l)};
    int mid=(l+r)/2+1;
    vi res=calc(mid);
    
//    cout<<endl;
    if (res.size()) return bs(mid,r);
    else return bs(l,mid-1);
}
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    for (i=0;i<n;i++) cin>>c[i];
    pair<int,vi> res=bs(1,n);
    cout<<res.fi<<' '<<res.se.size()<<endl;
    for (auto g: res.se) cout<<g-res.fi+2<<' '<<g+1<<endl;
}