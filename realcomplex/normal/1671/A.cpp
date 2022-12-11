#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 55;
int can[N];

int main(){
    fastIO;
    can[0] = 1;
    for(int i = 2; i < N; i ++ ){
        if(can[i - 2]) can[i] = 1;
        if(i >= 3 && can[i - 3]) can[i] = 1;
    }
    int tc;
    cin >> tc;
    bool res;
    for(int iq = 1; iq <= tc; iq ++ ){
        string t;
        cin >> t;
        int cnt = 0;
        char cur = '#';
        res = true;
        for(int i = 0 ;i < t.size(); i ++ ){
            cur = t[i];
            cnt ++ ;
            if(i + 1 == t.size() || t[i] != t[i + 1]){
                if(can[cnt] == 0) res = false;
                cnt = 0;
            }
        }
        if(res)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}