#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")


#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf =  (1<<30);
ll modulo = pow(10,9) + 7;

#define MAX 1'000'010

ll arr[MAX];
int bts[MAX];
int dps[MAX][60];
int tot[MAX];

bool debug = 0;

void divconq(ll l, ll r, ll& ans){
      if(l == r){
            ++ans;
            return;
      }
      ll mid = (l+r)/2;
      /*
      if(l == 0 && r == 9){
            debug = 1;
      }
      else{
            debug = 0;
      }
      */
      if(debug){
            cout<<"we here "<<l<<" "<<mid<<" "<<mid+1<<" "<<r<<endl;
      }
      
      {
            tot[r+1] = 0;
            ll mxid = mid+1, mnid = mid+1;
            for(ll i  = mid+1; i<=r; i++){
                  tot[i] = 0;
                  if(arr[i] > arr[mxid]){
                        mxid = i;
                  }
                  if(arr[i] < arr[mnid]){
                        mnid = i;
                  }
                  if(bts[mxid] == bts[mnid]){
                        ++tot[i];
                  }
            }
            for(ll i = r; i>mid; i--){
                  tot[i] += tot[i+1];
            }
      }
      {
            ll mxid = mid+1;
            forj(60){
                  dps[mid][j] = 0;
            }
            for(ll i = mid+1; i<=r; i++){
                  if(arr[i] > arr[mxid]){
                        mxid = i;
                  }
                  forj(60){
                        dps[i][j] = dps[i-1][j];
                  }
                  {
                        ll wh = bts[mxid];
                        dps[i][wh]++;
                  }
            }
      }
      {
            ll mxid = mid, mnid = mid;
            ll ptmin = mid, ptmax = mid;
            for(ll i =mid; i>=l; i--){
                  if(arr[i] > arr[mxid]){
                        mxid = i;
                  }
                  if(arr[i] < arr[mnid]){
                        mnid = i;
                  }
                  while(ptmax + 1 <= r && arr[mxid] > arr[ptmax+1]){
                        ++ptmax;
                  }
                  while(ptmin + 1 <= r && arr[mnid] < arr[ptmin + 1]){
                        ++ptmin;
                  }
                  if(ptmin == ptmax){
                        if(bts[mxid] == bts[mnid]){
                              ans += ptmin - mid;
                        }
                        ans += tot[ptmin+1] - tot[r+1];
                  }
                  else if(ptmin > ptmax){
                        if(bts[mxid] == bts[mnid]){
                              ans += ptmax - mid;
                        }
                        ll need = bts[mnid];
                        ans += dps[ptmin][need] - dps[ptmax][need];
                        
                        ans += tot[ptmin+1] - tot[r+1];
                  }
                  else{
                        // ptmax > ptmin
                        if(bts[mxid] == bts[mnid]){
                              ans += ptmin - mid;
                        }
                        
                        ans += tot[ptmax+1] - tot[r+1];
                  }
                  if(debug){
                        cout<<"so new answer is "<<ans<<endl;
                  }
            }
            {
                  ll cr = mid+1;
                  forj(60){
                        dps[mid][j] = 0;
                  }
                  for(ll i = mid+1; i<=r; i++){
                        if(arr[i] < arr[cr]){
                              cr = i;
                        }
                        forj(60){
                              dps[i][j] = dps[i-1][j];
                        }
                        {
                              ll wh = bts[cr];
                              dps[i][wh]++;
                        }
                  }
            }
            mxid = mid, mnid = mid;
            ptmin = mid, ptmax = mid;
            for(ll i =mid; i>=l; i--){
                  if(arr[i] > arr[mxid]){
                        mxid = i;
                  }
                  if(arr[i] < arr[mnid]){
                        mnid = i;
                  }
                  while(ptmax + 1 <= r && arr[mxid] > arr[ptmax+1]){
                        ++ptmax;
                  }
                  while(ptmin + 1 <= r && arr[mnid] < arr[ptmin + 1]){
                        ++ptmin;
                  }
                  if(ptmax > ptmin){
                        ll need = bts[mxid];
                        ans += dps[ptmax][need] - dps[ptmin][need];
                  }
            }
      }
      divconq(l, mid, ans);
      divconq(mid+1, r, ans);
}

void deal(){
      ll n;
      cin>>n;
      fori(n){
            cin>>arr[i];
            ll ed = arr[i];
            while(ed){
                  if(ed % 2 == 1){
                        bts[i]++;
                  }
                  ed/=2;
            }
      }
      
      ll ans = 0;
      divconq(0, n-1, ans);
      cout<<ans;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}