#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> pos[n];

    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int b[n], cur;
    cur = 1;

    for(int i = 0; i<n; i++){
        if(pos[i].size() % (n - i) != 0){
            cout << "Impossible";
            return 0;
        }

        for(int j = 0; j<((pos[i].size()) / (n - i)); j++){
            for(int k = 0; k<n - i; k++){
                b[pos[i][j * (n - i) + k]] = cur;
            }
            cur++;
        }


    }

    cout << "Possible" << endl;
    for(int i = 0; i<n; i++){
        cout << b[i] << " ";
    }


}