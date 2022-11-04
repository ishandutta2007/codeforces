#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    map<int,int> mp;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]),mp[a[i]]++;
    int cnt[3]={0,0,0};
    for(auto& [i,c] : mp) {
        cnt[min(c,2)]++;
    }
    return 0*printf("%d\n",cnt[2]+(cnt[1]+1)/2);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}