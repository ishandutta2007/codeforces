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

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h;

vector<ll> A;
vector<vector<string> > C(70001, vector<string>());

unordered_map<ll,ll> M;

ll TEN[10] = {0};


char ntc(ll i){

    if(i == 0)return '0';
    if(i == 1)return '1';
    if(i == 2)return '2';
    if(i == 3)return '3';
    if(i == 4)return '4';
    if(i == 5)return '5';
    if(i == 6)return '6';
    if(i == 7)return '7';
    if(i == 8)return '8';
    if(i == 9)return '9';

}

string tstr(ll i, ll d){

    string ans = "";
    ll i2 = i;
    for(ll c1 = 0; c1 < d; c1++){
        ans += ntc(i2%10);
        i2/=10;
    }
    reverse(all(ans));
    return ans;
}

ll sth(string s){
    ll ans = 0;
    ll t = 1;
    for(ll c1 = 0; c1 < s.length(); c1++){
        ans += t*(ll(s[s.length()-c1-1]) - ll('0'));
        t *= 10;
    }
    return ans*10+s.length();
}

void fix(ll i, ll d){

    ll a = A[i];
    set<ll> S;
    for(ll c1 = 0; c1 < 10-d; c1++){

        ll a2 = a%TEN[d];

        if(S.find(a2) == S.end()){
            ll h = a2*10 + d;
            if(M.find(h) == M.end())M[h] = 0;
            M[h]++;
            S.insert(a2);
        }

        C[i].push_back(tstr(a2,d));
       // cout << a2 << " " << C[i][sz(C[i])-1] << "\n";
        a /= 10;
    }

}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    ll t = 1;
    for(ll c1 = 0; c1 < 10; c1++){
        TEN[c1] = t;
        t*= 10;
    }

    cin >> n;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
        A.push_back(a);
        d = 1;
        for(ll c2 = 0; c2 < 9; c2++){
            fix(c1,d);
            d++;
        }
    }

    for(ll c1 = 0; c1 < n; c1++){

        for(ll c2 = 0; c2 < C[c1].size(); c2++){

            ll h = sth(C[c1][c2]);
           // cout << h << "\n";
            if(M[h] == 1){

                cout << C[c1][c2] << "\n";
                break;

            }

        }


    }

    return 0;
}