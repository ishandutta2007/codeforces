#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, U, d, h, mid;
    cin >> n >> U;

    int E[n];
    for(int i=0; i<n; i++){
        cin >> E[i];
    }

    vector<long double> eff;

    for(int i=0; i<n-2; i++){
        d=i+2;
        h=n;
        if(E[i+2] > E[i] + U) continue;
        for(int j=0; j<25; j++){
            mid=(d+h)/2;
            if(E[mid] > U + E[i]) h=mid;
            else d=mid;
        }

        eff.push_back((E[mid]-E[i+1]+0.0)/(E[mid]-E[i]));


    }

    sort(eff.begin(), eff.end());
    if(eff.empty()) cout << "-1";
    else cout << setprecision(15) << eff[eff.size() - 1];


}