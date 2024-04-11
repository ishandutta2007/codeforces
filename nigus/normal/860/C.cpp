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
ll e =1;

vector<string> wrong0;
vector<string> wrong1;

vector<string> junk0;
vector<string> junk1;

vector<ll> avail0;
vector<ll> avail1;

vector<string> Q1;
vector<bool> Q2;

bool tak0[200001] = {0};
bool tak1[200001] = {0};

vector<string> ANS1;
vector<string> ANS2;

ll stn(string s){
    ll ans = 0;
    if(s[0] == '0' && s.length() > 1)return -1;
    for(ll c1 = 0; c1 < s.length(); c1++){
        ll a = s[c1]-'0';
        if(a < 0 || a >= 10)return -1;
        ans *= 10;
        ans += a;
    }
    return ans;
}

string nts(ll x){
    ostringstream ss;
    ss << x;
    return ss.str();
}

ll id(ll i){

    if(i < 1 || i > n)return -1;
    if(i < e)return 1;
    return 0;
}

void mov(string s, string to){
    cout << "move " << s << " " << to << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    cin >> n;
    string s;
    string LONG = "";
    ll le = 0;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> s >> a;
        Q1.push_back(s);
        Q2.push_back(a);
        if(a == 1)e++;
        d = rand()%4;
        if(s.length() > le || (s.length() == le && rand()%2 == 1)){
            le = s.length();
            LONG = s;
        }
    }
    if(le < 6)LONG += "a";
    string alfa = "abfghdjkghfgdgjdfklgjasdje";
    for(ll c1 = 0; c1 < LONG.length(); c1+=2){
        LONG[0] = alfa[rand()%alfa.length()];
    }
    for(ll c1 = 0; c1 < n; c1++){
        s = Q1[c1];
        a = Q2[c1];
        ll st = stn(s);
        b = id(st);
        if(b == -1){
            if(a == 0){
                junk0.push_back(s);
            }
            else{
                junk1.push_back(s);
            }
        }
        else{
            if(a != b){
                if(a == 0){
                    wrong0.push_back(s);
                }
                else{
                    wrong1.push_back(s);
                }
            }
            if(b == 0){
                tak0[st] = 1;
            }
            else{
                tak1[st] = 1;
            }
        }
    }
    for(ll c1 = 1; c1 < e; c1++){
        if(!tak1[c1])avail1.push_back(c1);
    }
    for(ll c1 = e; c1 <= n; c1++){
        if(!tak0[c1])avail0.push_back(c1);
    }
    if(sz(junk0) + sz(junk1) == 0){
        if(sz(wrong0) + sz(wrong1) == 0){
            cout << "0\n";
            return 0;
        }
        if(sz(wrong0) != 0){
            ANS1.push_back(wrong0[sz(wrong0)-1]);
            ANS2.push_back(LONG);
            junk0.push_back(LONG);
            avail1.push_back(stn(wrong0[sz(wrong0)-1]));
            wrong0.pop_back();
        }
        else{
            ANS1.push_back(wrong1[sz(wrong1)-1]);
            ANS2.push_back(LONG);
            junk1.push_back(LONG);
            avail0.push_back(stn(wrong1[sz(wrong1)-1]));
            wrong1.pop_back();
        }
    }
    while(sz(avail0) + sz(avail1) > 0){
        if(sz(avail0) > 0){
            if(sz(wrong0) > 0){
                string fr = wrong0[sz(wrong0)-1];
                string to = nts(avail0[sz(avail0)-1]);
                ANS1.push_back(fr);
                ANS2.push_back(to);
                avail1.push_back(stn(fr));
                wrong0.pop_back();
                avail0.pop_back();
            }
            else{
                string fr = junk0[sz(junk0)-1];
                string to = nts(avail0[sz(avail0)-1]);
                ANS1.push_back(fr);
                ANS2.push_back(to);
                junk0.pop_back();
                avail0.pop_back();
            }
        }
        else{
            if(sz(wrong1) > 0){
                string fr = wrong1[sz(wrong1)-1];
                string to = nts(avail1[sz(avail1)-1]);
                ANS1.push_back(fr);
                ANS2.push_back(to);
                avail0.push_back(stn(fr));
                wrong1.pop_back();
                avail1.pop_back();
            }
            else{
                string fr = junk1[sz(junk1)-1];
                string to = nts(avail1[sz(avail1)-1]);
                ANS1.push_back(fr);
                ANS2.push_back(to);
                junk1.pop_back();
                avail1.pop_back();
            }
        }
    }
    cout << ANS1.size() << "\n";
    for(ll c1 = 0; c1 < ANS1.size(); c1++){
        mov(ANS1[c1], ANS2[c1]);
    }
    return 0;
}