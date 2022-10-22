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
ll n,m,T,k,q;

string s;

vector<ll> CS;

ll p26[10000] = {0};

int DP[10000] = {0};
int logt[10000] = {0};

int ctn(char ch){
    return ll(ch) - ll('a');
}

int seg(int i, int j){
    return (CS[j+1]-(p26[j-i+1]*CS[i])%big2 + big2)%big2;
}

int dp(ll i){
    if(i == n)return 0;
    if(DP[i] != -1)return DP[i];
    int ans = n-i + 1;
    bool mark[8001] = {0};
    for(int c1 = 1; c1 < n-i; c1++){
        if(c1 + 1 >= ans)break;
        int h = seg(i,i+c1-1);
        int b = 1;
        int l = i + c1;
        while(l + c1 <= n){
            if(mark[l])break;
            mark[l] = 1;
            if(logt[b] + c1 >= ans)break;
            int h2 = seg(l,l + c1 - 1);
            ans = min(ans, logt[b] + c1 + dp(l));
           // if(i == 6)cout << h << " " << h2 << "  -  " << c1 << "\n";
            if(h2 != h)break;
            b++;
            l += c1;
        }
        ans = min(ans, logt[b] + c1 + dp(l));
    }
    DP[i] = ans;
    //cout << i << " " << ans << "\n";
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    std::cin.sync_with_stdio(false);
    ll a,b,c,d,e;
    a = 1;
    ll l = 1;
    ll nex = 10;
    big2 = 1000000000 + rand()%1000;
    for(ll c1 = 0; c1 < 10000; c1++){
        p26[c1] = a;
        if(c1 == nex){
            l++;
            nex *= 10;
        }
        logt[c1] = l;
        a *= 26;
        a %= big2;
    }

    cin >> s;
    n = s.length();
    CS.push_back(0);
    for(ll c1 = 0; c1 < n; c1++){
        CS.push_back((26*CS[c1] + ctn(s[c1]))%big2);
        DP[c1] = -1;
    }

    cout << dp(0);

    return 0;
}