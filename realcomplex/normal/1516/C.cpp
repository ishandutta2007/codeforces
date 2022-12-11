#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
const int MAX = N * 2010;
bitset<MAX> can;

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> A(n);
    can[0] = 1;
    int cum = 0;
    for(int i = 0; i < n; i ++ ){
        cin >> A[i];
        can = (can | (can << A[i]));
        cum += A[i];
    }
    if(cum % 2 == 1){
        cout << "0\n";
        return 0;
    }
    if(cum % 2 == 0 && can[cum / 2]){
        int low = -1;
        int cur = 0;
        int sol = (int)1e9;
        for(int i = 0 ; i < n; i ++ ){
            cur = 0;
            while(A[i] % 2 == 0){
                A[i] /= 2;
                cur ++ ;
            }
            if(cur < sol){
                sol = cur;
                low = i;
            }
        }
        cout << "1\n" << low + 1 << "\n";
    }
    else{
        cout << "0\n";
    }

    return 0;
}