#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
const ll N = 1e5+10 , M = 10;
ll n , m , k , a[N][M] , ans[M] , ans1[N][M];
 
bool check( ll d ){
    ll siz=-1;
    for(ll i=0 ; i<n ; i++)
        for(ll j=0 ; j<m ; j++)
            ans1[i][j] = 1e9;
    for(ll j=0 ; j<m ; j++){
        deque< ll > dq ;
        ll sz=0;
        for(ll i=0 ; i<n ; i++){
            while( dq.size() && a[ dq.front() ][j] < a[i][j] )
                dq.pop_front();
            dq.push_front( i );
            if( i - dq.back() + 1 > d )
                dq.pop_back();
            if(i >= d - 1)
                ans1[sz ++][j] = a[ dq.back() ][j];
 
        }
        siz = sz;
    }
    for(ll i=0 ; i<siz ; i++){
        ll shot = 0;
        for(ll j=0 ; j<m ; j++)
            shot += ans1[i][j];
        if( shot <= k ){
            for(ll it=0 ; it<m ; it++)
                ans[it] = ans1[i][it];
            return true;
        }
    }
    return false;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(ll i=0 ; i<n ; i++)
        for(ll j=0 ; j<m ; j++)
            cin >> a[i][j];
    ll l = 0 , r = n+1;
    while( r - l > 1 ){
        ll mid = (r + l)/2;
        if( check( mid ) )
            l = mid;
        else
            r = mid;
    }
    for(ll i=0 ; i<m ; i++)
        cout << ans[i] << " ";
    cout << endl;
}