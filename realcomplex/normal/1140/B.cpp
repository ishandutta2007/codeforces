#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tes;
    cin >> tes;
    for(int i = 0; i < tes ; i ++ ){
        string s;
        int n;
        cin >> n >> s;
        int pf = 0;
        int sf = 0;
        for(int j = 0 ; j < n; j ++ ){
            if(s[j] == '>')
                break;
            pf ++ ;
        }
        for(int j = n-  1; j >= 0 ; j -- ){
            if(s[j] == '<')
                break;
            sf ++ ;
        }
        cout << min(pf,sf) << "\n";
    }
    return 0;
}