#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[200001][3];
ll mod=1000000007ll;
map<string,int>mp;
int timer=0;
bitset<100001>b[41];
int res=0;
int n,m;
int br=0;
void F(int cur,bitset<100001>bt,int cnt){
     if (m-cur+1+cnt<=res) return;
     res=max(res,cnt);
     if (br>=50000){
        cout<<res;
        exit(0);
     }
     br++;
     if (cur==m+1) return;
     if (!(bt&b[cur]).any()) F(cur+1,(bt|b[cur]),cnt+1);
     F(cur+1,bt,cnt);

}
bitset<100001>start;
bool cmp(bitset<100001>cur1,bitset<100001>cur2){
     return (cur1.count()<cur2.count());
}
int main()
{
   cin>>n>>m;
   int cnt=-1;
   for (int i=1;i<=n;i++){
       int q;cin>>q;
       if (q==1){
           cnt++;
       } else {
            string s;cin>>s;
            if (!mp[s]) mp[s]=++timer;
            b[mp[s]][cnt]=1;
       }
   }
   sort(b+1,b+m+1,cmp);
   F(1,start,0);
   cout<<res;
   return 0;
}
/*
4
GSGS
*/