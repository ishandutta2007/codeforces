#include<bits/stdc++.h>
using namespace std;


#define pii pair<int,int>
#define fi first
#define se second
int n,m,i,j,k,t,t1,u,v,a,b,res;
int zarr[100001],zl,zr;
vector<pii> bruh;
vector<int> lis;
string s;
signed main(){
    cin>>s;
    n=s.length();
    zl=0,zr=0;
    for (i=1;i<n;i++)
    {
        if (i<=zr)
        {
            zarr[i]=min(zarr[i-zl],zr-i+1);

        }
            for (j=zarr[i]+1;j+i-1<n;j++) if (s[0+j-1]!=s[i+j-1]) break;
            j--;
            zarr[i]=j;
            if (i+zarr[i]-1>zr)
            {
                zl=i;
                zr=i+zarr[i]-1;
            }
            lis.push_back(zarr[i]);
 //           cout<<i<<' '<<zarr[i]<<endl;
    }
    sort(lis.begin(),lis.end());
    for (i=1;i<n;i++) if (zarr[n-i]>=i)
    {
        bruh.push_back({i,(n)-(lower_bound(lis.begin(),lis.end(),i)-lis.begin())});
    }
    bruh.push_back({n,1});
    cout<<bruh.size()<<endl;
    for (i=0;i<bruh.size();i++) cout<<bruh[i].fi<<' '<<bruh[i].se<<endl;
}