#include<bits/stdc++.h>

using namespace std;

vector<int> fa(26);

int gfa(int x){return x==fa[x]?x:fa[x]=gfa(fa[x]);}
void solve(){
    int n; string st;
    cin>>n>>st;
    vector<int> nxt(26,-1),vis(26,0);
    iota(fa.begin(),fa.end(),0);
    int cnt=0;
    for (auto &i:st){
        int w=i-'a';
        if (nxt[w]<0){
            ++cnt;
            for (int ch=0;ch<26;++ch){
                if (!vis[ch]){
                    if (gfa(w)!=gfa(ch)||cnt==26){
                        fa[w]=ch;
                        nxt[w]=ch;
                        vis[ch]=1;
                        break;
                    }
                }
            }
        }
        i=nxt[w]+'a';
    }
    cout<<st<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}