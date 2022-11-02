#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;

    vector<int> sons[n];
    int p[n];
    for(int i=1; i<n; i++){
        cin >> p[i];
        p[i]--;
        sons[p[i]].push_back(i);
    }

    for(int i=0; i<n; i++){
        if(sons[i].size()==0) continue;
        
        x=0;
        for(int j=0; j<sons[i].size(); j++){
            if(sons[sons[i][j]].size()==0) x++;
        }

        if(x<3){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";



}