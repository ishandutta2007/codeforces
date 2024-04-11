#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2010;
vector<int>num={1110111,10010, 1011101,1011011,111010,1101011,1101111,1010010, 1111111, 1111011};
int f(int x){
    vector<int>v;
    for (int i=1;i<=7;i++){
        v.push_back(x%10);
        x/=10;
    }
    int res=0;
    for (int i=0;i<7;i++) {
            res+=((1<<i)*v[i]);
    }
    return res;
}
int val[1000];
bool ok[N][N];
int a[N];
int mx[1000][8];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i=0;i<(1<<7);i++) {
        val[i]=-1;
        for (int j=0;j<=7;j++) mx[i][j]=-1;
    }
    for (int i=0;i<10;i++) {
        num[i]=f(num[i]);
        val[num[i]]=i;
    }
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        string s;cin>>s;
        reverse(s.begin(),s.end());
        for (int j=0;j<7;j++){
            a[i]+=((1<<j)*(s[j]-'0'));
        }

    }
    for (int i=0;i<(1<<7);i++){
        for (int mask=0;mask<(1<<7);mask++){
            if ((mask&i)) continue;
//            if (i==num[1] && mask==64) {
//                cout<<"OK\n";
//                cout<<val[64^i]<<" "<<num[7]<<" "<<(i^64)<<" "<<i<<endl;
//            }
            mx[i][__builtin_popcount(mask)]=max(mx[i][__builtin_popcount(mask)],val[(mask^i)]);
        }
    }
    ok[n+1][0]=true;
    for (int i=n;i>=1;i--){
        for (int j=0;j<=k;j++){
            for (int t=0;t<=7 && t<=j;t++){
                if (mx[a[i]][t]!=-1){
                    ok[i][j]|=ok[i+1][j-t];
                }
            }
        }
    }
    vector<int>ans;
    for (int i=1;i<=n;i++){
        pair<int,int>cur={-1,-1};
        for (int t=0;t<=7 && t<=k;t++){
            if (!ok[i+1][k-t]) continue;
            cur=max(cur,(pair<int,int>{mx[a[i]][t],t}));
        }
        if (cur.first==-1){
            cout<<-1<<endl;
            return 0;
        }
        ans.push_back(cur.first);
        k-=cur.second;
    }
    for (auto i:ans) cout<<i;
    return 0;
}