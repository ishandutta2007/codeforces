#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
 
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
ll n,m,k,q,T;
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
 
const int MAXN = 300006;
 
string s;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll a,b,c,d,e;
    
    cin >> T;
    rep(c4,0,T){
        int F[4] = {0};
        n = 0;
        rep(c1,0,4){
            cin >> F[c1];
        }
        int AB[2] = {0};
        int AB2[2] = {0};
        cin >> s;
        n = sz(s);
        AB[0] = F[0] + F[2] + F[3];
        AB[1] = F[1] + F[2] + F[3];
 
        rep(c1,0,n){
            if(s[c1] == 'A'){
                AB2[0]++;
            }
            else{
                AB2[1]++;
            }
        }
        if(AB[0] != AB2[0] || AB[1] != AB2[1]){
           // cerr << "(badcount)";
            cout << "NO\n";
            continue;
        }
 
        vector<pii> ag, neutral, bg;
        char prev = 'X';
        int len = 0;
 
        pii BG = {0,0};
 
        rep(c1,0,n+1){
            if(c1 == n || s[c1] == prev){
                if(len >= 2){
                    if(len%2 == 1){
                        neutral.push_back({len/2, len/2});
                    }
                    else{
                        if(prev == 'B'){
                            ag.push_back({len/2, len/2-1});
                        }
                        else{
                            BG.first += (len/2-1);
                            BG.second += (len/2);
                            bg.push_back({len/2-1, len/2});
                        }
                    }
                }
 
                len = 0;
            }
            if(c1 == n)break;
 
            prev = s[c1];
            len++;
 
        }
 
        sort(all(bg));
        reverse(all(bg));

        sort(all(ag));
        reverse(all(ag));

 
        while(F[2] > 0){
            bool noo = 0;
            if(sz(ag) > 0){
                pii hej = ag.back();
                ag.pop_back();
                if(hej.first > 0){
                    hej.first--;
                    hej.second--;
                    F[2]--;
                    if(hej.first > 0)ag.push_back(hej);
                }
            }
            else{
                if(sz(neutral) > 0){
                    pii hej = neutral.back();
                    neutral.pop_back();
                    if(hej.first > 0){
                        hej.first--;
                        hej.second--;
                        F[2]--;
                        if(hej.first > 0)neutral.push_back(hej);
                    }
                }
                else{
                    if(F[2] <= BG.first){
                      //  cerr << F[2] <<  "  fds\n";
 
                        int baba = BG.second-BG.first;
 
                        trav(p, bg){
                            if(p.first < F[2]){
                                F[2]-=p.first;
                                p.second = 0;
                                p.first = 0;
                            }
                            else{
                                p.second -= F[2]+1;
                                F[2] = 0;
                                break;
                            }
                        }
                    }
                    else{
                        noo = 1;
                        break;
                    }
                }
            }
        }
 
        if(F[2] > 0){
            cout << "NO\n";
            continue;
        }
        trav(p, ag){
            if(p.second > 0)F[3] -= p.second;
        }
        trav(p, neutral){
            if(p.second > 0)F[3] -= p.second;
        }
        trav(p, bg){
            if(p.second > 0)F[3] -= p.second;
        }
 
        if(F[3] <= 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
 
 
 
        
    }
    
 
    return 0;
}