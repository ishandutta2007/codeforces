#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int> dd;
vector<char> sign;

const int N = (int)1e5 + 100;
const ll INF = (ll)1e15;

struct DC{
    int val;
    int li;
    int ri;
};

void solve(int l, int r){
    if(l >= r) return;
    ll mlt = 1ll;
    bool opp = false;
    if(dd[l] == 1){
        sign[l+1]='+';
        solve(l+1,r);
        return;
    }
    if(dd[r]==1){
        sign[r]='+';
        solve(l,r-1);
        return;
    }
    for(int i = l ; i <= r; i ++ ){
        mlt = (mlt * 1ll * dd[i]);
        if(mlt >= INF){
            opp = true;
            break;
        }
    }
    if(opp){
        for(int j = l+1; j <= r; j ++ ){
            sign[j]='*';
        }
        return;
    }
    vector<DC> els;
    els.push_back({0,0,0});
    for(int j = l ; j <= r; j ++ ){
        if(dd[j]==1){
            if(els.empty() || els.back().val != 1){
                els.push_back({1, j, j});
            }
            else{
                els.back().ri = j;
            }
        }
        else{
            els.push_back({dd[j], j, j});
        }
    }
    vector<ll> dp(els.size());
    vector<ll> opt(els.size());
    ll solu;
    for(int i = 1 ; i < els.size(); i ++ ){
        dp[i]=dp[i-1]+(els[i].ri-els[i].li+1)*1ll*els[i].val;
        opt[i]=i-1;
        solu = 1;
        for(int j = i ; j >= 1; j -- ){
            solu *= els[j].val;
            if(solu+dp[j-1] > dp[i]){
                dp[i] = solu+dp[j-1];
                opt[i]=j-1;
            }
        }
    }
    int tat = els.size() - 1;
    int nx;
    while(tat > 0){
        nx = opt[tat];
        if(nx == tat - 1){
            for(int j = els[tat].li; j <= els[tat].ri; j ++ ){
                sign[j]='+';
            }
        }
        else{
            for(int j = nx + 1; j <= tat; j ++ ){
                for(int x = els[j].li; x <= els[j].ri; x ++ ){
                    sign[x]='*';
                }
            }
            sign[els[nx+1].li]='+';
        }
        tat = nx;
    }
}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    int d;
    for(int i = 0 ; i < n; i ++ ){
        cin >> d;
        dd.push_back(d);
    }
    sign.resize(n+1,'?');
    string sha;
    cin >> sha;
    if(sha.size() == 1){
        for(int i = 0 ; i < n; i ++ ){
            sign[i]=sha[0];
        }
        for(int i = 0 ; i < n; i ++ ){
            cout << dd[i];
            if(i + 1 < n)
                cout << sign[i+1];
        }
        return 0;
    }
    bool mult = false, add = false, rem = false;
    for(char x : sha){
        if(x == '*') mult = true;
        else if(x == '-') rem = true;
        else add = true;
    }
    if(!mult){
        for(int i = 0 ; i < n; i ++ ){
            if(add) sign[i] = '+';
            else sign[i]='-';
        }
        for(int i = 0 ; i < n; i ++ ){
            cout << dd[i];
            if(i+1 < n)
                cout << sign[i+1];
        }
        cout << "\n";
        return 0;
    }
    if(!add){
        for(int i = 0 ; i < n; i ++ ){
            if(dd[i]==0){
                sign[i]='-';
                for(int j = i + 1; j < n; j ++ ){
                    sign[j]='*';
                }
                break;
            }
            else{
                sign[i]='*';
            }
        }
        for(int i = 0 ; i < n; i ++ ){
            cout << dd[i];
            if(i+1<n)
                cout << sign[i+1];
        }
        return 0;
    }
    int las = -1;
    for(int i = 0 ; i < n; i ++ ){
        if(dd[i] == 0){
            sign[las+1]='+';
            sign[i]='+';
            solve(las+1,i-1);
            las=i;
        }
    }
    if(las + 1 < n){
        sign[las+1]='+';
        solve(las+1,n-1);
    }
    for(int i = 0 ; i < n; i ++ ){
        cout << dd[i];
        if(i+1<n)
            cout << sign[i+1];
    }

    return 0;
}