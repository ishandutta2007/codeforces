#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

set<pii> ok;

void ins(int x, int y){
    ok.insert(mp(x-1,y));
    ok.insert(mp(x+1,y));
    ok.insert(mp(x,y+1));
    ok.insert(mp(x,y-1));
}

int main(){
    fastIO;
    int q;
    cin >> q;
    for(int tt =0 ;tt < q; tt ++ ){
        ok.clear();
        int b, w;
        cin >> b >> w;
        vector<pii> gg;
        gg.push_back(mp(2,2));
        ins(2,2);
        int i = 3;
        w--;
        while(1){
            if(i % 2 == 1){
                if(b==0)
                    break;
                gg.push_back(mp(2,i));
                ins(2,i);
                b--;
            }
            else{
                if(w==0)
                    break;
                gg.push_back(mp(2,i));
                ins(2,i);
                w--;
            }
            
            i ++;
        }
        for(auto p : gg)
            ok.erase(p);
        for(auto v : ok){
            if(v.fi % 2 == v.se % 2){
                if(w > 0){
                    gg.push_back(mp(v.fi,v.se));
                    w--;
                }
            }
            else{
                if(b > 0){
                    gg.push_back(mp(v.fi,v.se));
                    b--;
                }
            }
        }
        if(w == 0 && b == 0){
            cout << "YES\n";
            for(auto p : gg)
                cout << p.fi << " " << p.se << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}