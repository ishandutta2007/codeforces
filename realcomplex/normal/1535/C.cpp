#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int pf[2][2][N];

int get(int p, int q, int lf,int rf){
    int res = pf[p][q][rf];
    if(lf > 0)
        res -= pf[p][q][lf-1];
    return res;
}

bool check(int lf, int rf){
    if(get(lf % 2, 1, lf, rf) == 0 && get((lf % 2)^1, 0, lf, rf) == 0) return true;
    if(get(lf % 2, 0, lf, rf) == 0 && get((lf % 2)^1, 1, lf, rf) == 0) return true;
    return false;
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        string s;
        cin >> s;
        int n = s.size();
        for(int i = 0 ; i < n; i ++ ){
            for(int p = 0 ; p < 2; p ++ ){
                for(int q = 0; q < 2; q ++ ){
                    pf[p][q][i] = 0;
                }
            }
            if(s[i] != '?'){
                pf[i % 2][(s[i] - '0')][i] ++ ;
            }
            if(i > 0){
                for(int p = 0 ; p < 2; p ++ ){
                    for(int q =0 ; q < 2; q ++ ){
                        pf[p][q][i] += pf[p][q][i - 1];
                    }
                }
            }
        }
        int nex;
        int go;
        ll outp = 0;
        for(int i = 0 ; i < n; i ++ ){
            nex = i;
            for(int lg = 18; lg >= 0 ; lg -- ){
                go = nex + (1 << lg);
                if(go >= n) continue;
                if(check(i, go)){
                    nex = go;
                }
            }
            outp += nex - i + 1;
        }
        cout << outp << "\n";
    }
    return 0;
}