/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
#define pi 3.1415926535897
typedef long long ll;
//------------xc xch normie tm muoi tm phan tram no----------//
 int N,id;
int t[50010],s[50010],p[50010];
vector <int> p2,v;
 
vector <pair <int, int> > queries; 
int page[50010];
priority_queue <pair <int, int> > q; 
ll ans[50010];
 
void simulate(void){
    int i;
    
    REP(i,N) page[i] = s[i];
    
    ll T = 0;
    int next = 0;
    
    while(1){
        while(next < N && queries[next].first == T){
            int x = queries[next].second;
            q.push(make_pair(p[x], x));
            next++;
        }
        
        if(q.empty()){
            if(next == N) return;
            T = queries[next].first;
            continue;
        }
        
        int y = q.top().second;
        ll T2 = T + page[y];
        if(next < N) T2 = min(T2, (ll)queries[next].first);
        
        page[y] -= T2 - T;
        if(page[y] == 0){
            q.pop();
            ans[y] = T2;
        }
        
        T = T2;
    }
}
 
int main(){
	ofile;
	fio;
    
    int i;
    ll T;
    
    cin >> N;
    REP(i,N) cin>>t[i]>>s[i]>>p[i];
    cin >> T;
    REP(i,N) if(p[i] == -1) id = i;
    
    p2.push_back(0);
    p2.push_back(1000000001);
    REP(i,N) if(p[i] != -1) p2.push_back(p[i]);
    sort(p2.begin(),p2.end());
    REP(i,p2.size()-1) if(p2[i+1] - p2[i] >= 2) v.push_back((p2[i+1] + p2[i]) / 2);
    
    REP(i,N) queries.push_back(make_pair(t[i],i));
    sort(queries.begin(),queries.end());
    
    int low = 0, high = v.size();
    while(high-low > 1){
        int mid = (high + low) / 2;
        p[id] = v[mid];
        simulate();
        if(ans[id] >= T) low = mid; else high = mid;
        if(ans[id] == T) break;
    }
    
    cout << v[low] << endl;
    REP(i,N){
        cout << ans[i];
        if(i == N-1) cout << endl; else cout << ' ';
    }
}