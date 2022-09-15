#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
bool used[100001];
int usedmin[100001];
int usedmax[100001];
int main()
{
    int n,k;cin>>n>>k;
    for (int i=1;i<=k;i++){
        int x;cin>>x;
        if (used[x]) usedmax[x]=i;
        else {
            used[x]=true;
            usedmin[x]=i;
            usedmax[x]=i;
        }
    }
    int res=0;
    for (int i=1;i<=n;i++){
        if (used[i]){
            if (i+1<=n && usedmin[i]>usedmax[i+1]) res++;
            if (i-1>=1 && usedmin[i]>usedmax[i-1]) res++;
        } else res+=min({i+1,3,n-i+2});
    }
    cout<<res;
    return 0;
}