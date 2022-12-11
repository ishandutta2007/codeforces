#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 100;

bool mark[N];
int nx[N];

int main(){
    fastIO;
    for(int i = 2 ; i < N ; i ++ ){
        if(!mark[i]){
            for(int j = i * 2; j < N ; j += i){
                mark[j]=true;
            }
        }
    }
    for(int i = N - 2; i >= 0 ; i -- ){
        if(!mark[i]){
            nx[i]=i;
        }
        else{
            nx[i]=nx[i+1];
        }
    }
    int tc;
    cin >> tc;
    ll p, q;
    ll sol;
    for(int t = 1; t <= tc; t ++ ){
        ll d;
        cin >> d;
        p = nx[d+1];
        q = nx[p+d];
        cout << p*1ll*q << "\n";
    }
    return 0;
}