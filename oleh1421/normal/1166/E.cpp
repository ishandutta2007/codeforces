#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define MINX(a,b) if(a>b) a=b;
#define MAXX(a,b) if(a<b) a=b;
typedef long long ll;
using namespace std;
bitset<10001>bt[51];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,n;cin>>m>>n;
    for (int i=1;i<=m;i++){
        int s;cin>>s;
        for (int j=1;j<=s;j++){
            int x;cin>>x;
            bt[i][x-1]=1;
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=i+1;j<=m;j++){
            if ((bt[i]&bt[j]).count()==0){
                cout<<"impossible";
                return 0;
            }
        }
    }
    cout<<"possible";
    return 0;
}
//2 6 -2 -6  2