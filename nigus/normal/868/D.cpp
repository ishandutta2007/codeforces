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
ll n,m,k,q,w,h,T;

const ll maxl = 12;

bool exist[201][maxl][(1 << maxl)] = {0};

vector<string> fir;
vector<string> las;

ll now = 0;

ll conc(ll i, ll j){

    string fs = "";
    for(ll c1 = 0; c1 < maxl; c1++){
        if(c1 >= fir[i].length()){
            ll j2 = c1-fir[i].length();
            if(j2 < fir[j].length()){
                fs += fir[j][j2];
            }
        }
        else{
            fs += fir[i][c1];
        }
    }
    string ls = "";
    ll li = las[i].length();
    ll lj = las[j].length();
    for(ll c1 = 0; c1 < maxl; c1++){
        if(c1 >= las[j].length()){
            ll j2 = c1-lj;
            if(j2 < li){
                ls += las[i][li-j2-1];
            }
        }
        else{
            ls += las[j][lj-c1-1];
        }
    }
    reverse(all(ls));

    fir.push_back(fs);
    las.push_back(ls);


    for(ll c1 = 0; c1 < maxl; c1++){
        for(ll c2 = 0; c2 < (1 << (c1+1)); c2++){
            exist[now][c1][c2] |= exist[i][c1][c2];
            exist[now][c1][c2] |= exist[j][c1][c2];
        }
    }

    string mid = las[i]+fir[j];

    for(ll c2 = 0; c2 < maxl; c2++){
        for(ll c3 = 0; c3 < mid.length()-c2; c3++){
            ll t = 0;
            for(ll c4 = 0; c4 < c2+1; c4++){
                t  *= 2;
                t += mid[c3+c4]-'0';
            }
            exist[now][c2][t] = 1;
        }
    }

    for(ll c1 = 0; c1 < maxl; c1++){
        for(ll c2 = 0; c2 < (1 << (c1+1)); c2++){
            if(exist[now][c1][c2] == 0)return c1;
        }
    }

    return maxl;

}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;

    for(ll c1 = 0; c1 < n; c1++){

        string s;
        cin >> s;
        string fs = "";
        for(ll c2 = 0; c2 < maxl; c2++){
            if(c2 >= s.length())break;
            fs += s[c2];
        }
        string ls = "";
        for(ll c2 = s.length()-maxl; c2 < s.length(); c2++){
            if(c2 < 0)continue;
            ls += s[c2];
        }
        fir.push_back(fs);
        las.push_back(ls);


        for(ll c2 = 0; c2 < maxl; c2++){
            for(ll c3 = 0; c3 < s.length()-c2; c3++){
                ll t = 0;
                for(ll c4 = 0; c4 < c2+1; c4++){
                    t  *= 2;
                    t += s[c3+c4]-'0';
                }
                exist[c1][c2][t] = 1;
            }
        }
    }
    now = n-1;
    cin >> m;
    for(ll c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        now++;
        cout << conc(a,b) << "\n";
    }

    return 0;
}