#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool valid(int x){
    int dig;
    while(x > 0){
        dig = x % 10;
        if(dig != 0 && dig != 1 && dig != 2 && dig != 5 && dig != 8) return false;
        x /= 10;
    }
    return true;
}

int flip(int x){
    vector<int> ord;
    for(int q = 0; q < 2; q ++ ){
        int dig = x % 10;
        if(dig == 0 || dig == 1 || dig == 8) ord.push_back(dig);
        else{
            if(dig == 2) ord.push_back(5);
            else ord.push_back(2);
        }
        x /= 10;
    }
    int mlt = 1;
    int cum = 0;
    for(int i = ord.size() - 1; i >= 0 ; i -- ){
        cum += ord[i] * mlt;
        mlt *= 10;
    }
    return cum;
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n, m;
        cin >> n >> m;
        int ca = 0, cb = 0;
        string ash;
        cin >> ash;
        ca = (ash[0]-'0') * 10 + (ash[1] - '0');
        cb = (ash[3]-'0') * 10 + (ash[4] - '0');
        int na, nb;
        bool has = false;
        for(int ah = 0 ; ah < n; ah ++ ){
            for(int bh = 0 ; bh < m ; bh ++ ){
                na = (ca + ah) % n;
                nb = (cb + bh) % m;
                if(cb + bh >= m) na ++ ;
                na %= n;
                if(valid(na) && valid(nb) && flip(nb) < n && flip(na) < m){
                    if(na < 10) cout << "0";
                    cout << na << ":";
                    if(nb < 10) cout << "0";
                    cout << nb << "\n";
                    has=true;
                    break;
                }
            }
            if(has) break;
        }
    }
    return 0;
}