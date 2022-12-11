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
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc;t ++ ){
        int n, k;
        cin >> n >> k;
        char q;
        vector<int> c1(26), c2(26);
        for(int i = 1; i <= n; i ++ ){
            cin >> q;
            c1[q-'a']++;
        }
        for(int i = 1; i <= n; i ++ ){
            cin >> q;
            c2[q-'a']++;
        }
        bool answ = true;
        for(int v = 0; v < 26; v ++ ){
            if(c1[v] < c2[v]){
                answ = false;
                break;
            }
            else{
                if(c1[v]%k == c2[v]%k){
                    //c1[v] -= c2[v];
                    if(v == 25){
                        if(c1[v] != c2[v]){
                            answ = false;
                            break;
                        }
                    }
                    else{
                        c1[v] -= c2[v];
                        c1[v+1] += c1[v];
                    }
                }
                else{
                    answ = false;
                    break;
                }
            }
        }
        if(answ)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}