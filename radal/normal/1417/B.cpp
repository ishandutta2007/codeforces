#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << ": " << x << endl;
#define X first
#define Y second
#define mp make_pair
using namespace std; 
const long long int N=1e6+30;
pair<ll,ll> ind[N];
pair<ll,ll>a[N];
int main(){
	ios_base::sync_with_stdio(false);	cout.tie(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--){
        ll n,k;
        cin >> n >> k;
        rep (i,0,n){
            cin >> a[i].X;
            a[i].Y = i;
        }
        sort(a,a+n);
        ll p1=0,p2=n-1;
        ll t=1;
        while (p1 < p2){
            if (a[p1].X+a[p2].X > k){
                ind[a[p2].Y].X = t;
                ind[a[p2].Y].Y = p2;
                p2--;
                continue;
            }
            if (a[p1].X + a[p2].X == k){
                ind[a[p2].Y].X = t;
                ind[a[p2].Y].Y = p2;
                ind[a[p1].Y].X = 1-t;
                ind[a[p1].Y].Y = p1;
                p1++;
                p2--;
            }
            else{
                ind[a[p1].Y].X = 0;
                ind[a[p1].Y].Y = p1;
                p1++;
            }
        }
        set <ll> c,d;
        ll cnt1=0,cnt0=0;
        rep (i,0,n){
            if (i == a[p1].Y) continue;
            if (ind[i].X) {
                c.insert(a[ind[i].Y].X);
                if (a[ind[i].Y].X == k-a[p1].X) cnt1++;
         //       cout << 'c'<< ' ';
            }
            else {
                d.insert(a[ind[i].Y].X);
                if (a[ind[i].Y].X == k-a[p1].X) cnt0++;
            }
       //     debug(a[ind[i].Y].X);
        }
    //    ll cnt1 = c.count(k-a[p1].X);
      //  ll cnt0 = d.count(k-a[p1].X);
       // debug(k-a[p1].X);debug(cnt1);debug(cnt0);
        if (cnt1 >= cnt0) ind[a[p1].Y].X = 0;
        else ind[a[p1].Y].X = 1;
        rep (i,0,n) cout << ind[i].X << ' ';
        cout << endl;
        
    }
    return 0;
}