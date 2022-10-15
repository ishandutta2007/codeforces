#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define precision(n)   cout << setprecision(n) << fixed
#define sf(a)          scanf("%d",&a)
#define sf2(a,b)       scanf("%d %d",&a,&b)
#define sf3(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define pi             3.1415926535
#define eps            0.000001
#define gl(a)          scanf("%llu",&a)
#define mod            100000007
#define pf             printf
#define loop(ds,itr)   for ( auto itr = ds.begin(); itr != ds.end(); itr++ )
#define fr(i,n)        for ( int i = 0; i < n; i++ )
#define check(x)       cout << x << endl;
#define bug            cout << 'x' << endl;
#define srt(n)         (int)(sqrt(double(n))+eps)
#define e              2.71828182845
#define mp             make_pair
#define min4(a,b,c,d)  min(a,min(b,min(c,d)));
#define power(n,i)     (int)(pow(n,i)+eps)
#define inf            0x3f3f3f3f
#define MAX            100005
#define ff             first
#define ss             second
#define sqr(a)         a*a
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int,int > ii;
typedef priority_queue< int,vector<int>, greater<int> > pq_increasing;
typedef tree< ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
map < string,int > m;
set<string> s;
pair<string,int> arr[1005];
 
int main () {
    ///freopen("input.txt","r",stdin);
    ///freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    ///cin.tie(0);
    int n;
    cin >> n;
    fr(i,n) {
        cin >> arr[i].ff >> arr[i].ss;
        m[arr[i].ff] += arr[i].ss;
    }
    int mxm = -inf;
    loop(m,itr) mxm = max(mxm,itr->ss);
    loop(m,itr){
        if (itr->ss == mxm ) s.insert(itr->ff);
    }
    m.clear();
    string winner;
    fr(i,n) {
        m[arr[i].ff] += arr[i].ss;
        if ( m[arr[i].ff] >= mxm && s.find(arr[i].ff) != s.end() ) {
            winner = arr[i].ff;
            break;
        }
    }
    cout << winner << endl;
    return 0;
 
}