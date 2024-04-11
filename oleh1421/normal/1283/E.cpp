#pragma GCC Optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
const long long mod=998244353;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
int x[300001];
int cn[300001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i];
    sort(x+1,x+n+1);
    vector<int>v;
    v.push_back(x[1]);
    for (int i=2;i<=n;i++){
        if (v.back()==x[i]) continue;
        v.push_back(x[i]);
    }
    v[0]++;
    int res=1;
    for (int i=1;i<v.size();i++){
        if (v[i]==v[i-1]) continue;
        if (v[i]-1==v[i-1]){
            v[i]--;
        } else v[i]++,res++;
    }
    cout<<res<<" ";
    for (int i=1;i<=n;i++) cn[x[i]]++;
    set<int>st;
    for (int i=1;i<=n;i++){
        if (x[i]==x[i-1]) continue;
        if (cn[x[i]]>2){
            st.insert(x[i]-1);
            st.insert(x[i]);
            st.insert(x[i]+1);
        } else if (cn[x[i]]==2){
            if (st.find(x[i]-1)==st.end()){
                st.insert(x[i]-1);
                st.insert(x[i]);
            } else {
                st.insert(x[i]);
                st.insert(x[i]+1);
            }

        } else {
            if (st.find(x[i]-1)==st.end()) st.insert(x[i]-1);
            else if (st.find(x[i])==st.end()) st.insert(x[i]);
            else st.insert(x[i]+1);
        }
    }
    cout<<st.size();
    return 0;
}