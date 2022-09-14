#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
bitset<7001>bt[N];
vector<int>d[7001];
int ok[7001];
bitset<7001>check[7001];
int32_t main()
{
    for (int i=1;i<=7000;i++){
        for (int j=i;j<=7000;j+=i) d[j].push_back(i);
    }
    ok[1]=1;
    for (int i=2;i<=7000;i++){
        int p=d[i][1];
        int x=i;
        int cn=0;
        while (x%p==0){
            x/=p;
            cn++;
        }
        if (cn>1) ok[i]=0;
        else ok[i]=ok[x];
    }
    for (int i=1;i<=7000;i++){
        for (int j=1;j*i<=7000;j++){
            if (ok[j]) check[i][i*j]=1;
        }
    }
//    cout<<check.size()<<endl;
//    for (int i:check) cout<<i<<" ";
//    cout<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n,m;cin>>n>>m;
 
    for (int it=1;it<=m;it++){
        int type;cin>>type;
        if (type==1){
            int x,v;cin>>x>>v;
            bt[x]=0;
            for (int i:d[v]) bt[x][i]=1;
        } else if (type==2){
            int x,y,z;cin>>x>>y>>z;
            bt[x]=(bt[y]^bt[z]);
        } else if (type==3){
            int x,y,z;cin>>x>>y>>z;
            bt[x]=(bt[y]&bt[z]);
        } else {
            int x,v;cin>>x>>v;
            int res=(bt[x]&check[v]).count()%2;
            cout<<res;
        }
 
    }
    cout<<endl;
    return 0;
}