#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main()
{
    int n;
    cin >> n;
    int f[n];
    bool eq = false;
    ll w;
    for(int i = 0;i<n;i++){
        cin >> f[i];
        if(i>0){
            if(f[i]!=f[i-1]){
                eq = true;
            }
        }
    }
    if(eq == false){
        w = n;
        cout << 0 << " " << ((w-1)*(w)/2);
    }
    else{
        sort(f,f+n);
        ll p1,p2;
        p1 = 1;
        p2 = 1;
        for(int i = 1;i<n;i++){
            if(f[i] == f[i-1]){
                p1++;
            }
            else{
                break;
            }
        }
        for(int x = n-2;x>=0;x--){
            if(f[x] == f[x+1]){
                p2++;
            }
            else{
                break;
            }
        }
        w = p1*p2;
        cout << f[n-1] - f[0] << " " << w;
    }
    return 0;
}