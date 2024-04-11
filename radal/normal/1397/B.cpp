#include <bits/stdc++.h>
#define ll long long int
#define rep(i,l,r) for(ll i=l; i<r; i++)
#define debug(x) cerr << #x << ": " << x << endl;
using namespace std;
auto over = [](uint64_t A, uint64_t B){
    if ((A*B)/B == A) return 1;
    return 0;
};
const int N=1e5+11;
unsigned ll a[N];
int main(){
    ios:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unsigned ll n,sum=100000000000000000;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
    }
    sort(a,a+n);
    unsigned ll c=1;
    while (pow(c,n-1) <= a[n-1]){
        c++;
    }
   // debug (c);
    //if (a[n-1] - pow(c-1,n-1) < pow(c,n-1)-a[n-1]) c--;
    while (c){
        unsigned ll ans=0;
        rep(i,0,n){
            if (ans > sum) break;
            ans+=abs(a[i]-pow(c,i));

        }
     //   cout << pow(c,0);
        
        sum = min (sum,ans);
        //if (ans == 0 && n==100) cout << c << endl;
        c--;
      //  debug( over(sum,2));
    }

  //  debug(c);
    
    cout << sum;

    return 0;

}