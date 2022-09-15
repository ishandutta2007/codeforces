#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100001];
pair<int,int>h[1001];
bool res[200001];
int main()
{
   int n,k;cin>>n>>k;
   for (int i=1;i<=n;i++) cin>>a[i];
   int last=0;
   int cnt=0;
   for (int t=0;t<=150000;t++){
       for (int i=1;i<=k;i++) {
           if (a[h[i].first]==h[i].second){
               if (h[i].first<=n && h[i].first>=1) cnt++;
               h[i].first=++last;
               h[i].second=0;
           }
       }
       int d=round((100.0*cnt)/(n*1.0));
       for (int i=1;i<=k;i++){
            if (h[i].first<=n && h[i].first>=1){
                if (h[i].second+1==d) {
                    res[h[i].first]=true;
                }
            }
            h[i].second++;
       }
   }
   int sum=0;
   for (int i=1;i<=n;i++) sum+=res[i];
   cout<<sum;
   return 0;
}