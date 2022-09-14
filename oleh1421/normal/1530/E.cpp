//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=300010;
int cnt[30];
void solve(){
    string s;cin>>s;
    for (int i=0;i<30;++i) cnt[i]=0;
    for (auto i:s){
        cnt[i-'a']++;
    }
    vector<int>v;
    for (int i=0;i<26;i++){
        if (cnt[i]) v.push_back(i);
    }
    if (v.size()==1){
        cout<<s<<endl;
        return;
    }
    for (int i:v){
        if (cnt[i]==1){
            int pos=-1;
            string ans="";
            ans+=(i+'a');
            for (int j=0;j<26;j++){
                if (j==i) continue;
                for (int t=0;t<cnt[j];t++) ans+=(j+'a');
            }
            cout<<ans<<endl;
            return;
        }
    }
    int a=v[0];
    if (cnt[a]<=s.size()/2+1){
        string t="";
        for (auto i:s){
            if (i-'a'==a) continue;
            t+=i;
        }
        sort(t.begin(),t.end());
        reverse(t.begin(),t.end());
        cnt[a]-=2;
        string ans="";
        ans+=a+'a';
        ans+=a+'a';
        for (int i=2;i<s.size();i++){
            if (cnt[a]>0){
                if (i%2){
                    cnt[a]--;
                    ans+=a+'a';
                } else {
//                    cout<<"XXX"<<endl;
                    ans+=t.back();
                    t.pop_back();
                }
            } else {
//                cout<<"XXX"<<endl;
                ans+=t.back();
                t.pop_back();
            }
        }
        cout<<ans<<endl;
    } else if (v.size()==2){
        int b=v[1];
        string ans="";
        ans+=a+'a';
        for (int i=0;i<cnt[b];i++) ans+=b+'a';
        cnt[a]--;
        for (int i=0;i<cnt[a];i++) ans+=a+'a';
        cout<<ans<<endl;
    } else {
        int b=v[1];
        int c=v[2];
        string ans="";
        ans+=a+'a';
        ans+=b+'a';
        cnt[a]--;
        cnt[b]--;
        for (int i=0;i<cnt[a];i++) ans+=a+'a';
        cnt[a]=0;
        ans+=c+'a';
        cnt[c]--;
        for (int i=0;i<cnt[b];i++) ans+=b+'a';
        cnt[b]=0;
        for (int j=0;j<26;j++){
            for (int t=0;t<cnt[j];t++) ans+=(j+'a');
        }
        cout<<ans<<endl;
    }

}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
abbccaaaaaaaaaa
**/