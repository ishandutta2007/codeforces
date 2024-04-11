#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
vector<int>g[200001];
char s[200001];
bool used[200001];
void dfs(int v){
     used[v]=true;
     for (auto to:g[v]){
        if (!used[to]) dfs(to);
     }
}
int p[200001];
int p1[200001];
int q[200001];
int q1[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    char a,b,c,d;cin>>a>>b>>c>>d;
    string s="";
    for (int i=int('a');i<=int('c');i++){
        for (int j=int('a');j<=int('c');j++){
            for (int t=int('a');t<=int('c');t++){
                char x=char(i);
                char y=char(j);
                char z=char(t);
                if (x==y || y==z || x==z) continue;
                if (x==a && y==b) continue;
                if (x==c && y==d) continue;
                if (z==a && x==b) continue;
                if (z==c && x==d) continue;
                if (y==a && z==b) continue;
                if (y==c && z==d) continue;
                s=x;
                s+=y;
                s+=z;
            }
        }
    }
    if (!s.empty()){
    cout<<"YES\n";
    for (int i=1;i<=n;i++) cout<<s;
    return 0;
    }
    vector<int>v;
    for (int i=int('a');i<=int('c');i++){
        for (int j=int('a');j<=int('c');j++){
            for (int t=int('a');t<=int('c');t++){
                char x=char(i);
                char y=char(j);
                char z=char(t);
                if (x==y || y==z || x==z) continue;
                if (x==a && y==b) continue;
                if (x==c && y==d) continue;
                if (y==a && z==b) continue;
                if (y==c && z==d) continue;
                v.push_back(int(x));
                v.push_back(int(y));
                v.push_back(int(z));
            }
        }
    }
    if (!v.empty()){
        cout<<"YES\n";
        for (int i=1;i<=n;i++) cout<<char(v[0]);
        for (int i=1;i<=n;i++) cout<<char(v[1]);
        for (int i=1;i<=n;i++) cout<<char(v[2]);
        return 0;
    }
    cout<<"NO";
    return 0;
}


///2007521364118