#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2010;
int pf[N];
int A[N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i ++ ){
            cin >> A[i];
            pf[i] = (pf[i - 1] ^ A[i]);
        }
        bool soln = false;
        for(int i = 1; i <= n - 1; i ++ ){
            if(pf[i] == (pf[n] ^ pf[i])){
                soln = true;
            }
        }
        int p0, p1, p2;
        for(int i = 1; i <= n; i ++ ){
            for(int j = i + 1; j <= n - 1; j ++ ){
                p0 = pf[i];
                p1 = (pf[j] ^ pf[i]);
                p2 = (pf[n] ^ pf[j]);
                if(p0 == p1 && p1 == p2){
                    soln = true;
                }
            }
        }
        if(soln)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}