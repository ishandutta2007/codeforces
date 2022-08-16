///   BISMILLAHIR RAHMANIR RAHEEM

#include<bits/stdc++.h>

using namespace std;

#define MUHAMMAD        ios::sync_with_stdio(0);cin.tie(0);

using ll = long long;

const int N = 2e5 + 5;


ll tr[N<<2] , lz[N<<2];
ll n;
ll arr[N];
ll q;


///1. Merge left and right
ll combine (ll left, ll right) {
    return __gcd(left , right);
}


void build(ll u, ll st, ll en) {
    if (st==en) {
        tr[u] = arr[st];
    }
    else {
        ll mid = (st+en)/2;
        build(2*u, st, mid);
        build(2*u+1, mid+1, en);
        tr[u]= combine(tr[2*u], tr[2*u+1]);
    }
}

pair<ll,ll> query(ll u, ll st, ll en, ll l, ll r,ll gc) {

    if (r<st || en<l)  return {0,en};        /// 5. Proper null value
    
    else if (l<=st && en<=r)    {
        ll vv = __gcd(gc,tr[u]);
        
        if(vv > 1) return {vv,en};
       
        if(st == en) return {0,st-1};
    }
    
    ll mid = (st+en)/2;
    
    pair<ll,ll> q1 = query(2*u,st,mid,l,r,gc);
    
    if(q1.second == mid) return query(2*u+1,mid+1,en,l,r,q1.first);
    else return q1;
}

void Solution ( int tc ){

  cin >> n;
  ll brr[n+1];
  for ( int i = 1 ; i<=n ; ++i ) cin >> brr[i];

  if ( n == 1 ) {
    cout << 1 << "\n";
    return;
  }

  for ( int i = 1 ; i<n ; ++i ) {
    arr[i] = abs ( brr[i] - brr[i+1] );
  }

  n--;

  build ( 1 , 1 , n );



  ll mx = 0;

  for ( int i = 1 ; i <= n ; ++i ) {

    ll lo = i;
    ll hi = n;

    ll mxrig = 0;
    ll mnlef = i;

    mxrig = query(1,1,n,i,n,0).second;
      
    /*

    lo = 1;
    hi = i;

    while ( lo<=hi ) {
        ll mid = (lo+hi)>>1;
        ll x = query ( 1 , 1 , n , mid , hi );

        if ( x > 1 and arr[i]%x == 0 ) {
           hi = mid - 1;
           mnlef = min ( mnlef , mid );
        }
        else lo = mid + 1;
    }

    */

    mx = max ( mx , mxrig - mnlef + 2 );



  }

  cout << mx << "\n";





  return;
}

int main()
{

    MUHAMMAD;




   /// AE;

   /*
   #ifdef OJ
        freopen("window.in", "r", stdin);
        freopen("output.txt", "w", stdout);
   #endif
   */



    int testcase = 1 , tc = 0;


    cin >> testcase;

    for ( int i = 1 ; i <= testcase ; ++i ){
       Solution( ++tc );
    }


    return 0;
}


  /// __mhs, Do you check
  /// -> overflow
  /// -> array bound.


/*
 LCA:
 https://codeforces.com/contest/1304/problem/E
Explanation:
 Time :
----------------------------------------------------------------------------------------------------------------
  Alhamdulillah
*/