#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair
#define MAXN 2000

ll k[50];

void calc(int c){
    if(c==50){
        return;
    }
    k[c] = k[c-1]+k[c-2];
    calc(c+1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    k[0] = 0;
    k[1] = 1;
    calc(2);
    ll n;
    cin >> n;
    for(int j = 0;j<50;j++){
        for(int x = 0;x<50;x++){
            for(int i = 0;i<50;i++){
                if(k[j]+k[x]+k[i] == n){
                    cout << k[j] << " " << k[i] << " " << k[x];
                    exit(0);
                }
            }
        }
    }
    cout << "I'm too stupid to solve this problem";
    return 0;
}