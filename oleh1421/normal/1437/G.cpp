#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const pair<ll,ll> mod={988763125,1000000007};
const int K=700;
pair<ll,ll> pw[N];
string s[N];
int a[N];
pair<ll,ll> Hash[N];
multiset<int>st[N];
int TOT=1;
int last[N];
int go[N][27];
int mx[N];
void add(int ind){
    int v=1;
    for (int i=0;i<s[ind].size();i++){
        if (!go[v][s[ind][i]-'a']) go[v][s[ind][i]-'a']=++TOT;
        v=go[v][s[ind][i]-'a'];
    }
    st[v].insert(0);
    last[ind]=v;
    mx[v]=0;
}
pair<ll,ll> pref[N];
int main()
{
    pw[0]={1ll,1ll};
    for (int i=1;i<N;i++){
        pw[i].first=(pw[i-1].first*29ll)%mod.first;
        pw[i].second=(pw[i-1].second*29ll)%mod.second;
        mx[i]=-1;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int>big;
    for (int i=1;i<=n;i++){
        cin>>s[i];
        a[i]=0;
        if (s[i].size()<=K) add(i);
        else {
            Hash[i]={0ll,0ll};
            for (int j=0;j<s[i].size();j++){
                Hash[i].first+=pw[j].first*(s[i][j]-'a'+1ll);
                Hash[i].first%=mod.first;
                Hash[i].second+=pw[j].second*(s[i][j]-'a'+1ll);
                Hash[i].second%=mod.second;
            }
            big.push_back(i);
        }
    }
    for (;m;m--){
        int type;cin>>type;
        if (type==1){
            int i,x;cin>>i>>x;
            if (s[i].size()<=K){
                st[last[i]].erase(st[last[i]].find(a[i]));
                a[i]=x;
                st[last[i]].insert(a[i]);
                mx[last[i]]=(*st[last[i]].rbegin());
            } else {
                a[i]=x;
            }
        } else {
            int res=-1;
            string t;cin>>t;
            for (int i=0;i<t.size();i++){
                int v=1;
                int pos=i;
//                cout<<i<<" ";
                while (v && pos<t.size()){
                    v=go[v][t[pos]-'a'];
                    if (v) res=max(res,mx[v]);
                    pos++;
                }
            }
            pref[0]={0,0};
            for (int i=0;i<t.size();i++){
                pref[i+1].first=(pref[i].first+pw[i].first*(t[i]-'a'+1ll))%mod.first;
                pref[i+1].second=(pref[i].second+pw[i].second*(t[i]-'a'+1ll))%mod.second;
            }
            for (int i:big){
                for (int j=1;j+s[i].size()-1<=t.size();j++){
                    if ((Hash[i].first*pw[j-1].first)%mod.first==(pref[j+s[i].size()-1].first-pref[j-1].first+mod.first)%mod.first && (Hash[i].second*pw[j-1].second)%mod.second==(pref[j+s[i].size()-1].second-pref[j-1].second+mod.second)%mod.second) res=max(res,a[i]);
                }
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
/*
5 1
kurou
takuo
takeshi
naomi
shingo
2 abanaomicaba
*/