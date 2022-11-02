#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n], b[n];
    int mi = 1e9;
    int ma = 0;
    int posi, posa;

    vector<pair<int, int> > dec, inc;
    for(int i = 0; i<n; i++){
        cin >> a[i] >> b[i];

        if(a[i] > b[i]){
            dec.push_back({b[i], i});
        }

        else{
           inc.push_back({b[i], i});
        }
    }

    sort(dec.begin(), dec.end());
    sort(inc.begin(), inc.end());
    reverse(inc.begin(), inc.end());

    cout << max(dec.size(), inc.size()) << endl;

    if(dec.size() > inc.size()){
        for(auto i: dec) cout << i.second + 1 << " ";
    }

    else for(auto i: inc) cout << i.second + 1 << " ";





}