#include <bits/stdc++.h>

using namespace std;
int n;
map<long long, long long> oszlop, sor;
map<pair<long long, long long>, long long> azonosak;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        oszlop[x]++;
        sor[y]++;
        azonosak[make_pair(x, y)]++;
    }

    long long db=0;
    for (auto par:oszlop) {
        db+=par.second*(par.second-1)/2;
    }
    for (auto par:sor) {
        db+=par.second*(par.second-1)/2;
    }
    for (auto par:azonosak) {
        db-=par.second*(par.second-1)/2;
    }
    cout << db << endl;
    return 0;
}