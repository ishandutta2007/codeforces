#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n, s, h, ans;
    long double hh;
    ans=0;
    string res;
    cin >> n;

    string t[n];
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    pair<long double, int> frac[n];
    for(int i=0; i<n; i++){
        s=0;
        h=0;
        for(int j=0; j<t[i].size(); j++){
            if(t[i][j]=='s') s++;
            else h++;
        }
        hh=h;

        if(h!=0) frac[i]=make_pair(s/hh, i);
        else frac[i]=make_pair(1000000000.0, i);
    }

    sort(frac, frac + n);
    reverse(frac, frac + n);
    for(int i=0; i<n; i++){
        res.append(t[frac[i].second].begin(), t[frac[i].second].end());
    }

    s=0;

    for(int i=0; i<res.size(); i++){
        if(res[i]=='s') s++;
        else ans+=s;
    }

    cout << ans;



}