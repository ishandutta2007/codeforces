#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,q,h,T,k;

string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";

ll l0,l1,l2,l3;

ll F[55] = {0};


ll f(ll i){
    if(i == 0)return s0.length();
    if(i >= 54)return 1000000000000000001;
    if(F[i] != 0)return F[i];
    ll ans = l1+l2+l3+2*f(i-1);
    F[i] = ans;
    return ans;
}

char solve(ll i, ll j){
    if(i == 0){
        if(j < l0){return s0[j];}
        else{return '.';}
    }
    if(j < l1)return s1[j];
    if(j < l1+f(i-1))return solve(i-1,j-l1);
    if(j < l1+l2+f(i-1))return s2[j-l1-f(i-1)];
    if(j < l1+l2+f(i-1)+f(i-1))return solve(i-1,j-l1-l2-f(i-1));
    if(j < l1+l2+f(i-1)+f(i-1)+l3)return s3[j-l1-l2-2*f(i-1)];
    return '.';
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
     l0 = s0.length();
     l1 = s1.length();
     l2 = s2.length();
     l3 = s3.length();

    cin >> q;

    for(ll c1 = 0; c1 < q; c1++){
        cin >> n >> k;
        k--;
        cout << solve(n,k);

    }

    return 0;
}