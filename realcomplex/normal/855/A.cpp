#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    string k;
    set<string>c;
    for(int j = 0;j<n;j++){
        cin >> k;
        if(c.count(k) == 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
        c.insert(k);
    }
    return 0;
}