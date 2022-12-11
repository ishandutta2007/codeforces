#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 110;
int A[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        char f;
        for(int i = 1; i <= n; i ++ ){
            cin >> f;
            A[i] = f - '0';
        }
        int las = -3;
        int res = 0;
        for(int i = 1; i <= n; i ++) {
            if(A[i] == 0){
                if(i - las == 1) res += 2;
                else if(i - las == 2) res ++ ;
                las = i;
            }
        }
        cout << res << "\n";
    }
    return 0;
}