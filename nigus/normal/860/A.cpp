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

string vows = "aeiou";
string s;
bool vow[30] = {0};

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    for(ll c1 = 0; c1 < 5; c1++){
        vow[vows[c1]-'a'] = 1;
    }


    cin >> s;
    string ans = "";
    n = s.length();
    ll cns = 0;
    bool same = 0;
    ll prev = -1;
    for(ll c1 = 0; c1 < n; c1++){
        a = s[c1]-'a';
        if(!vow[a]){

            if(cns == 0){
                same = 1;
                cns++;
            }
            else{

                if((!same) || (cns >= 2 && a != prev)){
                    ans += " ";
                    same = 1;
                    cns = 1;
                }
                else{
                    if(a != prev)same = 0;
                    cns++;
                }

            }

        }
        else{
            cns = 0;
            same = 0;
        }
        prev = s[c1]-'a';
        ans += s[c1];
    }

    cout << ans << "\n";

    return 0;
}