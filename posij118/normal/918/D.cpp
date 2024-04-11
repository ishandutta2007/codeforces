#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, y;
    char c;
    cin >> n >> m;

    vector<int> act;
    vector<int> temp;
    vector<pair<int, int> > g[n];
    vector<int> gop[n];
    for(int i=0; i<m; i++){
        cin >> x >> y >> c;
        g[x-1].push_back(make_pair(y-1, c-'a'));
        gop[y-1].push_back(x-1);
    }

    vector<int> clo;
    int rem[n];
    for(int i=0; i<n; i++){
        rem[i]=g[i].size();
    }

    for(int i=0; i<n; i++){
        if(rem[i]==0) clo.push_back(i);
    }

    for(int i=0; i<clo.size(); i++){
        for(int j=0; j<gop[clo[i]].size(); j++){
            rem[gop[clo[i]][j]]--;
            if(rem[gop[clo[i]][j]]==0) act.push_back(gop[clo[i]][j]);
        }
    }

    bool dp[n][n][26];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<26; k++){
                dp[i][j][k]=0;
            }
        }
    }

    while(clo.size()<n){
            for(int i=0; i<act.size(); i++){
                for(int j=0; j<clo.size(); j++){
                    for(int k=0; k<26; k++){
                        for(int l=0; l<g[act[i]].size(); l++){
                            if(k<=g[act[i]][l].second){
                                if(dp[clo[j]][g[act[i]][l].first][g[act[i]][l].second]==0) dp[act[i]][clo[j]][k]=1;
                            }
                        }
                    }
                }
            }

            for(int i=0; i<clo.size(); i++){
                for(int j=0; j<act.size(); j++){
                    for(int k=0; k<26; k++){
                        for(int l=0; l<g[clo[i]].size(); l++){
                            if(k<=g[clo[i]][l].second){
                               if(dp[act[j]][g[clo[i]][l].first][g[clo[i]][l].second]==0) dp[clo[i]][act[j]][k]=1;
                            }
                        }
                    }
                }
            }

            for(int i=0; i<act.size(); i++){
                for(int j=0; j<act.size(); j++){
                    for(int k=0; k<26; k++){
                        for(int l=0; l<g[act[i]].size(); l++){
                            if(k<=g[act[i]][l].second){
                                if(dp[act[j]][g[act[i]][l].first][g[act[i]][l].second]==0) dp[act[i]][act[j]][k]=1;
                            }
                        }
                    }
                }
            }

            for(int i=0; i<act.size(); i++){
                for(int j=0; j<gop[act[i]].size(); j++){
                    rem[gop[act[i]][j]]--;
                    if(rem[gop[act[i]][j]]==0) temp.push_back(gop[act[i]][j]);
                }

                clo.push_back(act[i]);
            }

            act.clear();
            for(int i=0; i<temp.size(); i++){
                act.push_back(temp[i]);
            }
            temp.clear();


    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dp[i][j][0]==1) cout << 'A';
            else cout << 'B';
        }
        cout << endl;
    }



}