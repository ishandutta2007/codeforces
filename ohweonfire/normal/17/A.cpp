#include <iostream>
using namespace std;
int b[1005];
bool a[1005];
int main()
{
    int m=0;
    int n,k;
    cin>>n>>k;
    int i,j;
    for(i=2;i<=n;i++)
    if(!a[i]){
        b[m++]=i;
        for(j=i*2;j<=n;j+=i)
        a[j]=true;
    }
    for(i=0;i<m;i++)
    if(!a[b[i]+b[i+1]+1]&&b[i]+b[i+1]<=n)k--;
    if(k>0)cout<<"NO";else cout<<"YES";
    return 0;
}