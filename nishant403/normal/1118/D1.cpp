#include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)

    void d()
    {
        //specially made for debuggin
        cout <<"hello";
    }
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

   //   freopen("input.txt","r",stdin);

    int i,j,n,m;
    int p,q;
    cin >> n >> m;

    int a[n];
    int sum=0;
    int ans=1000;
    f(i,n) {  cin >> a[i]; sum+=a[i]; }

    sort(a,a+n);

   f(i,n)
    {

    if(sum < m) break;
      long long l=1,r=1000,mid;
     while(l<=r)
       {
        mid=(l+r)/2;
        q=mid;
        p=n-i-q;

        if(sum- q*((p/q)*(p/q+1))/2-(p%q)*(p/q+1) >=m){  ans=min(ans,q);  r=mid-1;        }
        else l=mid+1;

    }
    sum-=a[i];
    }

if(ans==1000) cout <<"-1";
else cout << ans;
        return 0;
    }