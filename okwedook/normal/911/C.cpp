#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() { 
    map<ll, ll> mymap;
    ll temp;
    for (int i = 0; i < 3; ++i) {
        cin >> temp;
        mymap[temp]++;
    }
    if (mymap[1] >= 1 || mymap[2] >= 2 || mymap[3] >= 3 || (mymap[2] == 1 && mymap[4] == 2))
        cout << "YES";
    else
        cout << "NO";
    //system("pause");     
    return 0; 
}