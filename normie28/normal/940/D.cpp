#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define war(i,s,n) for(long long i=s;i<n;i++)
#define pb push_back
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fr first
#define sc second
#define mod 1000000007
#define vctr2d vector<vector<long long>>
#define vctr vector<long long>
#define pll pair<long long,long long>
#define rz(n) resize(n)
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mod2  998244353
#define arrin(a,n) for(int i = 0; i < n ; i++){cin>>a[i];}
#define arrout(a,n) for(int i = 0;i < n; i++){cout<<a[i]<<" ";}
#define ex(s) cout<<s<<endl;exit(0);
#define itr iterator
#define tra(it,m) for(it=m.begin();it!=m.end();++it)
 
int main()
{
          int n;
          cin>>n;
          int a[n];
          arrin(a,n);
          int b[n];
          war(i,0,n)
          {
                    char xx;
                    cin>>xx;
                    b[i] = xx - '0';
          }
          int l = -mod+7;
          int r = mod-7;
          war(i,0,n)
          {
                    if(b[i] == 0 && b[i-1] == 1)
                    {
                              int mini = a[i];
                              war(j,1,5)
                              {
                                        mini = min(mini,a[i-j]);
                              }
                              mini--;
                              r = min(r,mini);
                    }
                    if(b[i] == 1 && b[i-1] == 0)
                    {
                              int maxi = a[i];
                              war(j,1,5)
                              {
                                        maxi = max(maxi,a[i-j]);
                              }
                              maxi++;
                              l = max(maxi,l);
                    }
          }
          cout<<l<<" "<<r<<endl;
}