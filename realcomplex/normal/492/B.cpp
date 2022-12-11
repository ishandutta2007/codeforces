#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    double sl;
    cin >> n >> sl;
    double c[n];
    for(int i = 0;i<n;i++){
        cin >> c[i];
    }
    sort(c,c+n);
    double len = -(1e9);
    len = max(len,c[0]);
    len = max(len,abs(sl-c[n-1]));
    for(int i = 1;i<n;i++){
        len = max(len,(c[i]-c[i-1])/2);
        if(i!=n-1){
            len = max(len,(c[i+1]-c[i])/2);
        }
    }
    cout << setprecision(15)<<len;
    return 0;
}