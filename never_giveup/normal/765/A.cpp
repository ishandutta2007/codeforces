#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

int n;

map<string, int> mp;

map<pair<int, int>, int> q;

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif // ONPC
    cin >> n;
    if (n % 2 == 1)
        cout << "contest";
    else
        cout << "home";

}