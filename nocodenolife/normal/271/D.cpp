#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define repl(i,a,b) for(ll i=a;i<=b;++i)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define sll set<ll>
#define mp make_pair
#define M 1000000007
#define ln length()
int k;ll ans;
string s,alp;
vector<string> str;
struct trie{
    char c;
    int mark,lf;
    trie* chrn[27];
};
void dfs(trie* cur){
    if(cur->mark) ans++;
    if(cur->lf) return;
    rep(i,1,26) if(cur->chrn[i]) dfs(cur->chrn[i]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>alp>>k;
    trie* root=new trie;
    root->c='/';
    root->mark=0;root->lf=0;
    rep(i,1,26) root->chrn[i]=NULL;
    rep(i,0,s.ln-1){
       trie *cur=root;
       rep(j,i,s.ln-1){
            if(cur->chrn[s[j]-'a'+1]) cur=cur->chrn[s[j]-'a'+1];
            else{
                trie* nc=new trie;
                cur->lf=0;
                nc->c=s[j];
                nc->mark=0;nc->lf=1;
                rep(kk,1,26) nc->chrn[kk]=NULL;
                cur->chrn[s[j]-'a'+1]=nc;
                cur=nc;
            }
       }
    }
    rep(i,0,s.ln-1){
        trie* cur=root;
        int ct=0;
        rep(j,i,s.ln-1){
            cur=cur->chrn[s[j]-'a'+1];
            if(alp[s[j]-'a']-'0') ct++;
            if(ct>=j-i+1-k) cur->mark=1;
        }
    }
    dfs(root);
    cout<<ans;
}