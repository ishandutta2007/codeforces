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
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, r, b;
        cin >> n >> r >> b;
        int res = r/(b+1);
        int mod = r%(b+1);
        while(r > 0){
            for(int i = 0 ; i < res; i ++ ){
                cout << "R";
                r -- ;
            }
            if(mod > 0){
                mod -- ;
                cout << "R";
                r -- ;
            }
            if(b){
                cout << "B";
                b -- ;
            }
        }
        while(b > 0) {
            cout << "B";
            b -- ;
        }
        cout << "\n";
    }
    return 0;
}