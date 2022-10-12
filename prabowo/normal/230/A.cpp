#include<bits/stdc++.h>
using namespace std;

int main(){
    long long s,n;
    pair <long long, long long> st[1001];
    cin >> s >> n;
    long i,j,k;
    for(i=0; i<n; i++){
        cin >> st[i].first >> st[i].second;
    }
    sort(st,st+n);
    for(i=0; i<n; i++){
        if (s <= st[i].first) break;
        s += st[i].second;
    }

    if (i == n) cout << "YES"; else cout << "NO";
    cout << endl;
    return 0;
}