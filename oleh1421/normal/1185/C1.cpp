#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[2000001];
int dp[101][200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   int n,m;cin>>n>>m;
   for (int i=1;i<=n;i++) cin>>a[i];
   cout<<0<<" ";
   multiset<int>st;
   st.insert(a[1]);
   for (int i=2;i<=n;i++){
       int sum=0;
       int cnt=0;
       for (auto j:st){
            if (sum+j>m-a[i]) break;
            sum+=j;
            cnt++;
       }
       st.insert(a[i]);
       cout<<i-cnt-1<<" ";
   }
  /* for (int x=max(m-100,0);x<=m;x++){
       int sum=a[1];
       int cnt=0;
       if (sum>x){
          sum=0;
          cnt=1;
       }
       multiset<int>st;
       if (cnt==0) st.insert(a[1]);
       dp[m-x][1]=0;
       for (int i=2;i<=n;i++){
           dp[m-x][i]=cnt;
           //cout<<x<<" "<<i<<" "<<cnt<<endl;
           if (sum+a[i]<=x){
              sum+=a[i];
              st.insert(a[i]);
            } else {
              if (!st.empty() && *st.rbegin()>a[i]){
                  int maxx=*st.rbegin();
                  st.erase(st.find(maxx));
                  sum-=maxx;
                  st.insert(a[i]);
              }
              cnt++;

           }
       }
   }
   for (int i=1;i<=n;i++){
       cout<<dp[a[i]][i]<<" ";
   }*/
   return 0;
}