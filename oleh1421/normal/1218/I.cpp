#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
bool a[2001][2001];
bool b[2001][2001];
bool mask[2001];
bool c[2001][2001];
int32_t main()
{
    int n;cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char c;cin>>c;
            a[i][j]=(c=='1');
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            char c;cin>>c;
            b[i][j]=(c=='1');
        }
    }
    for (int i=0;i<n;i++){
        char c;cin>>c;
        mask[i]=(c=='1');
    }
    vector<pair<string,int> >ans;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) c[i][j]=a[i][j];
    int ind=0;
    while (!mask[ind] && ind<n) ind++;
    if (ind==n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (c[i][j]!=b[i][j]){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<0;
    return 0;
    }
    for (int i=0;i<n;i++){
        if (c[ind][i]!=b[ind][i]){
            ans.push_back({"col",i});
            for (int j=0;j<n;j++) c[j][i]^=mask[j];
        }
    }
    for (int i=0;i<n;i++){
        if (c[i][ind]!=b[i][ind]){
            ans.push_back({"row",i});
            for (int j=0;j<n;j++) c[i][j]^=mask[j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (c[i][j]!=b[i][j]){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<ans.size()<<endl;
    for (auto cur:ans) cout<<cur.first<<" "<<cur.second<<endl;
    return 0;
}