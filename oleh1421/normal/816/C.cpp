#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int g[101][101];
int main()
{
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++) {
            cin>>g[i][j];
        }
    }

    if (n<m){
    vector<int>row;
    for (int i=1;i<=n;i++){
        int minx=1000000001;
        for (int j=1;j<=m;j++) {
            minx=min(minx,g[i][j]);
        }
        for (int j=1;j<=minx;j++) row.push_back(i);
        for (int j=1;j<=m;j++) g[i][j]-=minx;
    }
    vector<int>col;
    for (int j=1;j<=m;j++){
        int minx=1000000001;
        for (int i=1;i<=n;i++){
            minx=min(minx,g[i][j]);
        }
        for (int i=1;i<=minx;i++) col.push_back(j);
        for (int i=1;i<=n;i++) g[i][j]-=minx;

    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (g[i][j]){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<(int)row.size()+(int)col.size()<<endl;
    for (auto i:row){
        cout<<"row "<<i<<endl;
    }
    for (auto i:col){
        cout<<"col "<<i<<endl;
    }
    return 0;
    }

    vector<int>col;
    for (int j=1;j<=m;j++){
        int minx=1000000001;
        for (int i=1;i<=n;i++){
            minx=min(minx,g[i][j]);
        }
        for (int i=1;i<=minx;i++) col.push_back(j);
        for (int i=1;i<=n;i++) g[i][j]-=minx;

    }
    vector<int>row;
    for (int i=1;i<=n;i++){
        int minx=1000000001;
        for (int j=1;j<=m;j++) {
            minx=min(minx,g[i][j]);
        }
        for (int j=1;j<=minx;j++) row.push_back(i);
        for (int j=1;j<=m;j++) g[i][j]-=minx;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (g[i][j]){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<(int)row.size()+(int)col.size()<<endl;
    for (auto i:col){
        cout<<"col "<<i<<endl;
    }
    for (auto i:row){
        cout<<"row "<<i<<endl;
    }

    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4