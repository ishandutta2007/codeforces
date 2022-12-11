#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second

int main()
{
    int n,te;
    cin >> n >> te;
    pair<int,int>s[n],k[n];
    for(int i = 0;i<n;i++){
        cin >> s[i].fi;
        s[i].se = i;
    }
    sort(s,s+n);
    bool c = true;
    int add = 0;
    for(int x = 0;x<n;x++){
        k[x].fi = s[x].se;
        k[x].se = (s[x].fi/2) + (s[x].fi%2);
        if(te < (s[x].fi/2) + (s[x].fi%2)){
            c = false;
            break;
        }
        else{
            te -=(s[x].fi/2) + (s[x].fi%2);
        }
    }
    if(c==false){
        cout << -1;
    }
    else{
        for(int x = n-1;x>=0;x--){
            add = min(s[x].fi-k[x].se,te);
            k[x].se += add;
            te -= add;
        }
        sort(k,k+n);
        for(int i = 0;i<n;i++){
            cout << k[i].se << " ";
        }
    }
    return 0;
}