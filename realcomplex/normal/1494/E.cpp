#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<pii, char> faf;
int c0 = 0, c1 = 0;

void add(pii xx, int sign){
    int uu = xx.fi;
    int vv = xx.se;
    if(faf.count(mp(uu, vv))){
        if(faf.count(mp(vv, uu))){
            c0 += sign;
            if(faf[mp(uu, vv)] == faf[mp(vv, uu)]){
                c1 += sign;
            }
        }
    }
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    char typ;
    int ui;
    int vi;
    char k;
    for(int i = 1; i <= m ; i ++ ){
        cin >> typ;
        if(typ == '+'){
            cin >> ui >> vi >> k;
            add(mp(ui, vi), -1);
            faf[mp(ui,vi)]=k;
            add(mp(ui, vi), +1);
        }
        else if(typ == '-'){
            cin >> ui >> vi;
            add(mp(ui,vi), -1);
            faf.erase(mp(ui, vi));
            add(mp(ui,vi), +1);
        }
        else{
            cin >> ui;
            if(ui % 2 == 1){
                if(c0 > 0){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
            else{
                if(c1 > 0){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}