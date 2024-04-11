#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string s[n];
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    sort(s, s + n);

    int used[m];
    fill(used, used + m, 0);

    for(int i=0; i<m; i++){
        if(s[0][i]=='#') used[i]++;
    }
    for(int i=1; i<n; i++){
        if(s[i]!=s[i-1]){
            for(int j=0; j<m; j++){
                if(s[i][j]=='#') used[j]++;
            }
        }
    }

    for(int i=0; i<m; i++){
        if(used[i]>=2){
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

}