//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=101;
vector<string>get(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    vector<string>v;
    for (int i=l;i<=r;i++){
        for (int j=i;j<=r;j++){
            string s;cin>>s;
            sort(s.begin(),s.end());
            v.push_back(s);
        }
    }
    return v;
}
string pref[N];
int cnt[26];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<string>a=get(1,n);
    if (n==1){
        cout<<"! "<<a[0]<<endl;
        return 0;
    }
    vector<string>b=get(2,n);
    multiset<string>st;
    for (auto x:a) st.insert(x);
    for (auto x:b) st.erase(st.find(x));
    for (auto x:st){
        pref[x.size()]=x;
    }
    string s=pref[1];
    for (int i=2;i<=n;i++){
        for (auto x:pref[i-1]) cnt[x-'a']--;
        for (auto x:pref[i]) cnt[x-'a']++;
        for (int j=0;j<=25;j++){
            if (cnt[j]>0){
                cnt[j]=0;
                s+=char(j+'a');
                break;
            }
        }
    }
    cout<<"! "<<s<<endl;
    return 0;
}