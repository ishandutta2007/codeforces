#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=345231431ll;
ll hash1[1000001];
ll hash2[1000001];
ll p[1000001];
ll f(char c){
    if (c>='0' && c<='9') return (c-'0');
    else if (c>='a' && c<='z') return (c-'a')+10;
    else return (c-'A')+36;
}
string a;
int marge(string b){
    hash2[0]=0ll;
    for (int i=0;i<b.size();i++){
        hash2[i+1]=hash2[i]+p[i]*f(b[i])*1ll;
        hash2[i+1]%=mod;
    }
    int ind=(int)a.size();
    for (int i=max(0,(int)a.size()-(int)b.size());i<a.size();i++){
        ll h2=hash2[(int)a.size()-i];
        ll h1=hash1[(int)a.size()];
        h1+=mod-hash1[i];
        h1%=mod;
        h2*=p[i];
        h2%=mod;
        if (h1==h2){
            ind=i;
            break;
        }

    }
    return ind;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    p[0]=1ll;
    for (int i=1;i<=1000000;i++) {
        p[i]=(p[i-1]*67ll)%mod;
    }
    int n;cin>>n;
    cin>>a;
    hash1[0]=0ll;
    for (int i=0;i<a.size();i++){
        hash1[i+1]=hash1[i]+p[i]*f(a[i])*1ll;
        hash1[i+1]%=mod;
    }
    for (int i=2;i<=n;i++){
        string x;cin>>x;
        int ind=marge(x);
        while ((int)a.size()>ind) a.pop_back();
        a+=x;
        for (int i=ind;i<a.size();i++){
            hash1[i+1]=hash1[i]+p[i]*f(a[i]);
            hash1[i+1]%=mod;
        }
    }
    cout<<a;

    return 0;
}