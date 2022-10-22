#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;

ll n,m,k,T,q;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    string s1,s2;
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    if(s1 == s2){
        cout << s1 << "\n";
    }
        else{
        if(n < m){
            sort(all(s1));
            reverse(all(s1));
            cout << s1 << "\n";
        }
        else{
            vl f1(10);
            vl f2(10);
            vl cands;

            a = 0;
            for(ll c1 = 0; c1 < n; c1++){
                a *= 10;
                a += s1[c1]-'0';
            }

            b = 0;
            for(ll c1 = 0; c1 < m; c1++){
                b *= 10;
                b += s2[c1]-'0';
            }

            ll a2 = a;
            ll b2 = b;

            for(ll c1 = 0; c1 < n; c1++){
                f1[a2%10]++;
                a2/=10;
            }
            for(ll c1 = 0; c1 < n; c1++){
                f2[b2%10]++;
                b2/=10;
            }

            bool sim = 1;
            for(ll c1 = 0; c1 < 10; c1++){
                if(f1[c1] != f2[c1])sim = 0;
            }

            if(sim){
                cout << s2 << "\n";
                return 0;
            }

            ll first = 0;
            ll dig = -1;
            for(ll c1 = 9; c1 >= 1; c1--){
                if(f1[c1] > 0 && c1 < s2[0]-'0'){
                    first += c1;
                    dig = c1;
                    break;
                }
            }
            if(dig != -1){

                for(ll c1 = 9; c1 >= 0; c1--){
                    for(ll c2 = 0; c2 < f1[c1] - (c1 == dig); c2++){
                        first *= 10;
                        first += c1;
                    }
                }
                cands.push_back(first);
            }
            ll num = 0;
            for(ll same = 1; same < n; same++){
                d = s2[same-1]-'0';
                if(f1[d] > 0){
                    num *= 10;
                    num += d;
                    f1[d]--;

                    dig = -1;

                    for(ll c1 = 9; c1 >= 0; c1--){
                        if(f1[c1] > 0 && c1 < s2[same]-'0'){
                            dig = c1;
                            break;
                        }
                    }
                    if(dig != -1){

                        ll num2 = num*10+dig;
                        for(ll c1 = 9; c1 >= 0; c1--){
                            for(ll c2 = 0; c2 < f1[c1]-(c1 == dig); c2++){
                                num2 *= 10;
                                num2 += c1;
                            }
                        }
                        cands.push_back(num2);

                    }

                }
                else{
                    break;
                }

            }

            ll ans = -1;
            for(ll c1 = 0; c1 < sz(cands); c1++){
                if(cands[c1] <= b){
                    ans = max(ans,cands[c1]);
                }
            }
            assert(ans != -1);
            cout << ans << "\n";

        }

    }

    return 0;
}