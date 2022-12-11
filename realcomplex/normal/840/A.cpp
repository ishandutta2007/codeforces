#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

int main(){

    int n;
    cin >> n;
    vector<int>a;
    vector<pair<int,int> >b;
    int s;
    for(int i = 0;i<n;i++){
        cin >> s;
        a.push_back(s);
    }
    for(int i = 0;i<n;i++){
        cin >> s;
        b.push_back(mp(s,i));
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans[n];
    for(int i = 0;i<n;i++){
        ans[b[i].se] = a[i];
    }
    for(int i = 0;i<n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}