#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=400010;
bool ok[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for (int x=25;x>=1;x--){
        for (int i=0;i<s.size();i++) ok[i]=false;
        string news="";
        char last=0;
        for (int i=0;i<s.size();i++){
            if (s[i]-'a'==x){
                if (last+1==s[i]) ok[i]=true;
            } else last=s[i];
        }
        last=0;
        for (int i=(int)s.size()-1;i>=0;i--){
            if (s[i]-'a'==x){
                if (last+1==s[i]) ok[i]=true;
            } else last=s[i];
        }
        for (int i=0;i<s.size();i++){
            if (ok[i]) continue;
            news+=s[i];
        }
        s=news;
    }
    cout<<n-s.size();
    return 0;
}