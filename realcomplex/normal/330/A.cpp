#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    map<int,int>t[2];
    int l[n][m];
    char s;
    for(int j = 0;j<n;j++){
        for(int i = 0;i<m;i++){
            cin >> s;
            l[j][i] = 0;
            if(s == 'S'){
                t[1][i]++;
                t[0][j]++;
            }

        }
    }
    int cnt = 0;
    for(int j = 0;j<n;j++){
        if(t[0][j] == 0){
            for(int x = 0;x<m;x++){
                if(l[j][x] == 0){
                    cnt++;
                    l[j][x] = 1;
                }
            }
        }
    }
    for(int j = 0;j<m;j++){
        if(t[1][j] == 0){
            for(int x = 0;x<n;x++){
                if(l[x][j] == 0){
                    cnt++;
                    l[x][j] = 1;
                }
            }
        }
    }
    cout << cnt;
	return 0;
}