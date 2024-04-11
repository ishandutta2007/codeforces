#include <bits/stdc++.h>
using namespace std;

int ton(char c){
    if(c=='0') return 0;
    if(c=='1') return 1;
    if(c=='2') return 2;
    if(c=='3') return 3;
}

int main(){
    int m, n, skap;
    skap=0;
    int ans=0;
    cin >> n >> m;
    pair<int, int> S;
    pair<int, int> e;
    pair<int, int> r;

    char grid[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
            if(grid[i][j]=='S') S=make_pair(i, j);
            if(grid[i][j]=='E') e=make_pair(i, j);
        }
    }

    int perm[4]={0, 1, 2, 3};
    string s;
    cin >> s;
    int t[s.size()];


    for(int j=0; j<24; j++){
        r=S;
        skap=0;
        next_permutation(perm, perm + 4);
        for(int i=0; i<s.size(); i++){
            t[i]=perm[ton(s[i])];
        }

        for(int i=0; i<s.size(); i++){
            if(t[i]==0) r.second++;
            else if(t[i]==1) r.second--;
            else if(t[i]==2) r.first--;
            else if(t[i]==3) r.first++;

            if(r.second<0 || r.second>=m || r.first<0 || r.first >=n) skap=1;
            else if(grid[r.first][r.second]=='#') skap=1;
            else if(grid[r.first][r.second]=='E'){
                ans++;
                skap=1;
            }

            if(skap==1) break;


        }

    }

    cout << ans;


}