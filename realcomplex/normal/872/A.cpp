#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    set<int>d1,d2;
    int k;
    for(int j = 0;j<n;j++){
        cin >> k;
        d1.insert(k);
    }
    for(int j = 0;j<m;j++){
        cin >> k;
        d2.insert(k);
    }
    int fir,sec;
    fir = -1;
    sec = -1;
    for(auto x : d1){
        if(fir == -1)fir = x;
        if(d2.count(x) == 1){
            cout << x;
            exit(0);
        }
    }
    for(auto x : d2){
        if(sec == -1) sec = x;
    }
    cout << min(fir,sec) << max(fir,sec);
    return 0;
}