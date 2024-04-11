#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;

int n,m,T,k,q;

vector<vector<ll> > C(1000001, vector<ll>());
vector<ll> A;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d,e;


    scanf("%d" , &n);

    ll nplus = 0;
    ll nminus = 0;
    ll ans = 0;
    for(ll c1 = 0; c1 < n; c1++){
        scanf("%d", &a);
        A.push_back(a);

        ll dist = (a-c1-1+n)%n;
        if(dist == 0)dist = n;
        C[dist].push_back(a);
        if(a <= c1+1){nplus++;}
        else{
            nminus++;
        }
        ans += abs(a-c1-1);
        //cout << dist << " " << abs(a-c1-1)<< "\n";
    }
    ll anst = ans;
    ll shift = 0;
    for(ll c1 = 1; c1 < n+2; c1++){

        //cout << ans << " +" << nplus << " -" << nminus << "   " << c1-1 << "\n";

        if(c1 == n+1)break;

        ans += nplus;
        ans -= nminus;

        a = A[n-c1];
        ans--;
        ans -= abs(n-a);
        ans += abs(1-a);
        nminus++;
        nplus--;

        nplus += sz(C[c1]);
        nminus -= sz(C[c1]);

        if(ans < anst){
            anst = ans;
            shift = c1;
        }
    }

    cout << anst << " " << shift << "\n";

    return 0;
}