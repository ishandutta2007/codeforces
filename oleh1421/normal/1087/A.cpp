#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool cmp(ll cur1,ll cur2){
    return cur1>cur2;
}

struct cran{
     double a;
     double t;
};
pair<ll,ll> c[100001];
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    int n=s.size();
    int pos;
    if (n%2) pos=n/2;
    else pos=n/2-1;
    string rez="";
    rez+=s[pos];
    for (int i=1;i<=pos;i++){
        rez+=s[pos+i];
        rez+=s[pos-i];
    }
    if (n%2==0) rez+=s[n-1];
    cout<<rez;
    return 0;
}