#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m, skap, x;
    skap=0;
    x=0;
    cin >> n >> m;
    int g[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> g[i][j];
        }
    }

    int a[m];
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
                a[j]=g[i][j]-g[0][j];
        }

        for(int j=1; j<m; j++){
            if(a[j]!=a[0]){
                skap=1;
                cout << "-1";
                break;
            }
        }

        if(skap==1) break;
    }

    vector<pair<int, char> > cut;

    if(skap==1){}
    else{
        if(n<=m){
            int mini[n];
            fill(mini, mini + n, 999999);
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                        mini[i]=min(mini[i], g[i][j]);
                }

            }

            for(int i=0; i<n; i++){
                for(int j=0; j<mini[i]; j++){
                    cut.push_back(make_pair(i+1, 'r'));
                    x++;
                }
            }

            for(int j=0; j<m; j++){
                for(int i=0; i<g[0][j]-mini[0]; i++){
                    cut.push_back(make_pair(j+1, 'c'));
                    x++;
                }
            }
        }

        else{
            int mini[m];
            fill(mini, mini + m, 999999);
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                        mini[i]=min(mini[i], g[j][i]);
                }

            }

            for(int i=0; i<m; i++){
                for(int j=0; j<mini[i]; j++){
                    cut.push_back(make_pair(i+1, 'c'));
                    x++;
                }
            }

            for(int j=0; j<n; j++){
                for(int i=0; i<g[j][0]-mini[0]; i++){
                    cut.push_back(make_pair(j+1, 'r'));
                    x++;
                }
            }
        }
        cout << cut.size() << endl;
        for(int i=0; i<cut.size(); i++){
            if(cut[i].second=='c') cout << "col " << cut[i].first << endl;
            else cout << "row " << cut[i].first << endl;
        }
    }
}