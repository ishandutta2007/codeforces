#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m, mini, a;
    mini=10000;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<int> positions;
    vector<int> positions_mini;

    for(int i=0; i<=m-n; i++){
        a=0;
        for(int j=0; j<n; j++){
            if(s[j]!=t[i+j]){
                a++;
                positions.push_back(j+1);
            }
        }

        if(a<mini){
            positions_mini.clear();

            for(int j=0; j<positions.size(); j++){
                positions_mini.push_back(positions[j]);
            }
            mini=a;
        }

         positions.clear();
    }

    cout << mini << endl;
    for(int i=0; i<mini; i++){
        cout << positions_mini[i] << " ";
    }


}