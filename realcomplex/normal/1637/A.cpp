#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e4 + 10;
int A[N];
int high[N];
int low[N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        for(int j = 0 ; j <= n + 1; j ++ ){
            low[j] = (int)1e9;
        }
        for(int i = 1; i <= n; i ++ ){
            cin >> A[i];
            high[i]=max(high[i-1],A[i]);
        }
        for(int i = n; i >= 1; i -- ){
            low[i]=min(low[i+1],A[i]);
        }
        bool answ = false;
        for(int i = 1; i <= n - 1; i ++ ){
            if(high[i] > low[i + 1]){
                answ = true;
            }
        }
        if(answ)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}