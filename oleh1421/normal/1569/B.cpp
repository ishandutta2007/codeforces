#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=510;
char A[N][N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            A[i][j]='.';
        }
    }
    for (int i=0;i<n;i++) A[i][i]='X';
    vector<int>v;
    for (int i=0;i<n;i++){
        if (s[i]=='1'){
            for (int j=0;j<n;j++){
                if (i==j) continue;
                A[i][j]=A[j][i]='=';
            }
        } else {
            v.push_back(i);
        }
    }
    if (v.size()==1 || v.size()==2){
        cout<<"NO\n";
        return;
    }
    for (int i=1;i<v.size();i++){
        A[v[i-1]][v[i]]='+';
        A[v[i]][v[i-1]]='-';
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            if (A[i][j]=='.'){
                A[i][j]='+';
                A[j][i]='-';
            }
        }
    }
    cout<<"YES\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) cout<<A[i][j];
        cout<<endl;
    }
}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}