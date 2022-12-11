#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 4010;
int a[N];
int b[N];
int aa[N];
int bb[N];

const int K = 16;
int las[1 << K];
int go[1 << K];

int gen(int m){
    return ((int)rng() % m + m) % m;
}

void rev(int pre){
    reverse(aa, aa + pre);
}

void solve(){
    string p;
    string q;
    cin >> p >> q;
    int n = p.size();
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    int d0 = 0;
    int d1 = 0;
    int d2 = 0;
    for(int i = 0 ; i < n; i ++ ){
        a[i]=p[i]-'0';
    }
    for(int i = 0 ; i < n; i += 2){
        if(a[i] == a[i + 1]){
            if(a[i] == 0) c0 ++ ;
            else c1 ++ ;
        }
        else{
            c2 ++ ;
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        b[i]=q[i]-'0';
    }
    for(int i = 0 ; i < n; i += 2){
        if(b[i] == b[i + 1]){
            if(b[i] == 0) d0 ++ ;
            else d1 ++ ;
        }
        else{
            d2 ++ ;
        }
    }
    if(c0 != d0 || c1 != d1 || c2 != d2){
        cout << "-1\n";
        return;
    }
    if(n <= 16){
        for(int i = 0 ; i < (1 << n); i ++ ){
            las[i] = -1;
            go[i] = -1;
        }
        int st = 0;
        int en = 0;
        for(int i = 0 ; i < n; i ++ ){
            if(a[i]) st += (1 << i);
            if(b[i]) en += (1 << i);
        }

        queue<int> bf;
        bf.push(st);
        las[st] = -2;
        go[st] = -2;
        int node;
        int nw;
        while(!bf.empty()){
            node = bf.front();
            bf.pop();
            for(int i = 2; i <= n; i += 2){
                nw = 0;
                for(int p = 0 ; p < n; p ++ ){
                    if(p < i){
                        if((node & (1 << (i - p - 1)))) nw |= (1 << p);
                    }
                    else{
                        if((node & (1 << p))) nw |= (1 << p);
                    }
                }
                if(las[nw] == -1){
                    las[nw] = node;
                    go[nw] = i;
                    bf.push(nw);
                }
            }
        }
        if(las[en] == -1){
            cout << "-1\n";
            return;
        }
        vector<int> ans;
        while(en != st){
            ans.push_back(go[en]);
            en = las[en];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for(auto x : ans){
            cout << x << " ";
        }
        cout << "\n";
    }
    else{
        bool fin;
        int g;
        for(int iter = 0; iter < 5; iter ++ ){
            for(int i = 0 ; i < n; i ++ ){
                aa[i] = a[i];
                bb[i] = b[i];
            }
            vector<int> sol;
            if(iter > 0){
                g = gen(n / 2) * 2 + 2;
                sol.push_back(g);
                rev(g);
            }
            for(int it = n - 2; it >= 0 ; it -= 2 ){
                if(aa[it] == bb[it] && aa[it + 1] == bb[it + 1]) continue;
                if(bb[it] == bb[it + 1]){
                    for(int t = 0; t < it; t += 2){
                        if(aa[t] == bb[it] && aa[t + 1] == bb[it]){
                            if(t == 0){
                                sol.push_back(it + 2);
                                rev(it + 2);
                            }
                            else{
                                sol.push_back(t + 2);
                                rev(t + 2);
                                sol.push_back(it + 2);
                                rev(it + 2);
                            }
                            break;
                        }
                    }
                }
                else{
                    fin = false;
                    if(aa[0] == bb[it + 1] && aa[1] == bb[it]){
                        sol.push_back(it + 2);
                        rev(it + 2);
                        continue;
                    }
                    for(int t = 0; t < it; t += 2){
                        if(aa[t] == bb[it] && aa[t + 1] == bb[it + 1]){
                            sol.push_back(t + 2);
                            rev(t + 2);
                            sol.push_back(it + 2);
                            rev(it + 2);
                            fin = true;
                            break;
                        }
                    }
                    if(!fin){
                        for(int t = 0; t <= it; t += 2){
                            if(aa[t] == bb[it + 1] && aa[t + 1] == bb[it]){
                                sol.push_back(t + 2);
                                rev(t + 2);
                                sol.push_back(2);
                                rev(2);
                                sol.push_back(it + 2);
                                rev(it + 2);
                                break;
                            }
                        }
                    }
                }
            }
            if(sol.size() <= n + 1){
                cout << sol.size() << "\n";
                for(auto x : sol){
                    cout << x << " ";
                }
                cout << "\n";
                return;
            }
        }
        cout << "-1\n";
        return;
    }
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}