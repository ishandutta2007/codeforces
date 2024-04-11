#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll n,m,k,T;

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

ll NDIV[100001] = {0};


ll bin(ll i, ll j){
    ll ans = 1;
    for(int c1 = 0; c1 < j; c1++){
        ans *= i-c1;
    }
    for(int c1 = 1; c1 <= j; c1++){
        ans /= c1;
    }
    return ans;
}

ll brute(ll a, ll b, ll c){
    ll ans = 0;
    for(int c1 = 1; c1 <= 100; c1++){
        for(int c2 = c1; c2 <= 100; c2++){
            for(int c3 = c2; c3 <= 100; c3++){

                vl F;
                F.push_back(a);F.push_back(b);F.push_back(c);
                for(int c4 = 0; c4 < 6; c4++){
                    if(F[0]%c1 == 0 && F[1]%c2 == 0 && F[2]%c3 == 0){
                        ans++;
                        break;
                    }
                    next_permutation(all(F));
                }

            }
        }
    }
    return ans;
}

int main(){
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c;

    for(int c1 = 1; c1 <= 100000; c1++){
        for(int c2 = c1; c2 <= 100000; c2 += c1){
            NDIV[c2]++;
        }
    }

    cin >> T;
    for(int c4 = 0; c4 < T;c4++){
        cin >> a >> b >> c;
        ll A = NDIV[a];
        ll B = NDIV[b];
        ll C = NDIV[c];
        ll g = gcd(a,gcd(b,c));
        ll ABC = NDIV[g];
        ll AB = NDIV[gcd(a,b)];
        ll AC = NDIV[gcd(a,c)];
        ll BC = NDIV[gcd(b,c)];
        ll AB2 = AB-ABC;
        ll AC2 = AC-ABC;
        ll BC2 = BC-ABC;

        ll A2 = A-AC2-AB2-ABC;
        ll B2 = B-BC2-AB2-ABC;
        ll C2 = C-AC2-BC2-ABC;

        ll ans = 0;
        ans += A2*B2*C2;

        ans += A2*B2*(C-C2);
        ans += A2*C2*(B-B2);
        ans += C2*B2*(A-A2);

        ans += A2*bin(BC,2);
        ans += A2*(AB2+AC2)*(ABC+BC2);
        ans += A2*AB2*AC2;

        ans += B2*bin(AC,2);
        ans += B2*(AB2+BC2)*(ABC+AC2);
        ans += B2*AB2*BC2;

        ans += C2*bin(AB,2);
        ans += C2*(BC2+AC2)*(ABC+AB2);
        ans += C2*AC2*BC2;

        ans += AB2*BC2*AC2;
        ans += bin(ABC,3);
        ans += (AB2+AC2+BC2)*bin(ABC,2);
        ans += AB2*BC2*ABC;
        ans += AB2*ABC*AC2;
        ans += BC2*AC2*ABC;

        ans += ABC*(bin(AC2,2) + bin(AB2,2) + bin(BC2,2));

        ans += AB2*(bin(AC2,2) + bin(BC2,2));
        ans += AC2*(bin(BC2,2) + bin(AB2,2));
        ans += BC2*(bin(AC2,2) + bin(AB2,2));

        //pairs
        ans += A*BC2;
        ans += B*AC2;
        ans += C*AB2;

        ans += ABC*(ABC-1+AB2+AC2+BC2+A2+B2+C2);
        ans += ABC;

        cout << ans << "\n";
       // cerr << brute(a,b,c);

    }
    return 0;
}