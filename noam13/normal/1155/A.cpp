#include<bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define chkmin(a,b) a=min((int)(a),(int)(b))
#define chkmax(a,b) a=max(a,b)
using namespace std;
const int INF=4*1e18;


int32_t main(){
    int n;cin>>n;
    string s; cin>>s;
    for(int i=0;i<n-1;i++){
        if (s[i]>s[i+1]){
            cout<<"YES"<<endl<<(i+1)<<" "<<(i+2)<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}