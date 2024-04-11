#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios_base::sync_with_stdio(false);cin.tie();cout.tie();

const int SIZ = (int)2e6 + 9;
char ans[SIZ];

int main(){
    fastIO;
    for(int i = 0;i<SIZ;i++)ans[i]='a';
    int n;
    cin >> n;
    string s[n];
    int k,v;
    int las=0,len=0;
    vector<pii>sk;
    for(int i = 0;i<n;i++){
        cin >> s[i] >> k;
        while(k--){
            cin >> v;
            len=max(len,(int)s[i].size() + v - 1);
            --v;
            sk.push_back(mp(v,i));
        }
    }
    sort(sk.begin(),sk.end());
    int l;
    for(auto x : sk){
        l=s[x.se].size();
        for(int j = max(las,x.fi);j<x.fi+l;j++){
            ans[j]=s[x.se][j-x.fi];
            las=max(las,j);
        }
    }
    for(int i = 0;i<len;i++)cout << ans[i];
    return 0;
}