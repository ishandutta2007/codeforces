#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int K = 60;
ll F[K];
vector<ll> c;
bool fin(int id, int las){
    bool soln = false;
    if(id == -1){
        soln = true;
        for(auto q : c) if(q != 0) soln = false;
        return soln;
    }
    for(int i = 0 ; i < c.size(); i ++ ){
        if(c[i] - F[id] >= 0 && i != las){
            c[i] -= F[id];
            soln |= fin(id - 1, i);
            if(soln) return true;
            c[i] += F[id];
        }
    }
    return soln;
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    F[0]=F[1]=1;
    for(int i = 2; i < K; i ++ ){
        F[i]=(F[i-1]+F[i-2]);
    }
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        ll mx = 0;
        c.clear();
        c.resize(n);
        for(int i = 0 ; i < n ; i ++ ){
            cin >> c[i];
            mx = max(mx, c[i]);
        }
        ll sigma = 0;
        for(int i = 0 ; i < n; i ++ ){
            sigma += c[i];
        }
        int m = -1;
        ll sum = 0;
        for(int i = 0 ; i < K; i ++ ){
            sum += F[i];
            if(sum == sigma){
                m = i; // kinda
            }
        }
        if(m == -1 || F[m] > mx){
            cout << "No\n";
            continue;
        }
        if(fin(m, -1)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}