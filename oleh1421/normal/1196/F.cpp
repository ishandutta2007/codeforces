#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int mp[200001];
int d[1001][1001];
template <class nmsl> inline void read(nmsl &x)
{
	x=0;
	char ch=getchar(), w=0;
	while(!isdigit(ch))w=(ch=='-'), ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	x=w?-x:x;
}
int32_t main() {
   /* ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int n,m,k;read(n);read(m);read(k);
    vector<pair<int,pair<int,int> > >u;
    for (int i=1;i<=m;i++){
        int a,b,c;read(a);read(b);read(c);
        u.push_back({c,{a,b}});
    }
    sort(u.begin(),u.end());
    while (u.size()>k) u.pop_back();
    int timer=0;
    for (int i=0;i<=1000;i++) for (int j=0;j<=1000;j++) d[i][j]=1000000000000001ll;
    for (auto cur:u){
        if (!mp[cur.second.first]) mp[cur.second.first]=++timer;
        if (!mp[cur.second.second]) mp[cur.second.second]=++timer;
        d[mp[cur.second.first]][mp[cur.second.second]]=cur.first;
        d[mp[cur.second.second]][mp[cur.second.first]]=cur.first;
    }
    for (int i=1;i<=timer;i++) d[i][i]=0;
    for (int i=1;i<=timer;i++){
        for (int j=1;j<=timer;j++){
            for (int t=1;t<=timer;t++){
                d[j][t]=min(d[j][t],d[j][i]+d[i][t]);
            }
        }
    }
    vector<int>ans;
    for (int i=1;i<=timer;i++){
        for (int j=i+1;j<=timer;j++){
            ans.push_back(d[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans[k-1];
    return 0;
}