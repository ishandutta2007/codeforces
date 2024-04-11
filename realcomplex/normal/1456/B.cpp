#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;
const int LOG = 31;
int a[N];
int c[N];
int pf[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1 ; i <= n; i ++ ){
        cin >> a[i];
    }
    int sol = (int)1e9;
    int las;
    for(int b = 0; b < LOG; b ++ ){
        las = 0;
        map<int,int> ids;

        for(int i = 1; i <= n; i ++ ){
            if((a[i] & (1 << b))){
                c[i]=1;
            }
            else{
                c[i]=0;
            }
            pf[i]=(pf[i-1]^a[i]);
            if(ids.count(pf[i]^(1<<b))){
                sol = min(sol, i - ids[(pf[i]^(1<<b))]);
            }
            if(c[i]){
                for(int j = las; j < i ; j ++ ){
                    ids[pf[j]]=j;
                }
                las=i;
            }
        }
        for(int i = 1 ; i <= n; i ++ ){
            if((a[i] & (1 << b))){
                a[i] ^= (1 << b);
            }
        }
    }
    if(sol > n){
        cout << "-1\n";
    }
    else{
        cout << sol-2 << "\n";
    }
    return 0;
}