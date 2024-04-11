#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second


int main()
{
    int n,s;
    cin >> s >> n;
    pair<int,int>stren[n];
    for(int i = 0;i<n;i++){
        cin >> stren[i].fi >> stren[i].se;
    }
    sort(stren,stren+n);
    bool c = true;
    for(int i = 0;i<n;i++){
        if(s > stren[i].fi){
            s += stren[i].se;
        }
        else{
            c = false;
            break;
        }
    }
    if(c == false){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
    return 0;
}