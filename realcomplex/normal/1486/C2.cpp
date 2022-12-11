#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int get(int li, int ri){
    cout << "? " << li << " " << ri << endl;
    fflush(stdout);
    int res;
    cin >> res;
    return res;
}

void fin(int li, int ri, bool en){ // en == false => li
    if(en == false){
        int nx;
        int go = li;
        for(int lg = 18; lg >= 0; lg -- ){
            nx = (go + (1 << lg));
            if(nx > ri) continue;
            if(get(li, nx) != li)
                go = nx;
        }
        cout << "! " << go + 1 << endl;
    }
    else{
        int nx;
        int go = ri;
        for(int lg = 18 ; lg >= 0 ;lg -- ){
            nx = (go - (1 << lg));
            if(nx < li) continue;
            if(get(nx, ri) != ri)
                go = nx;
        }
        cout << "! " << go - 1 << endl;
    }
}

int main(){
    fastIO;
    int n;
    cin >> n;
    int ova = get(1, n);
    if(ova == 1 || (ova < n && get(ova, n) == ova)){
        fin(ova,n,false);
    }
    else{
        fin(1,ova,true);
    }
    return 0;
}