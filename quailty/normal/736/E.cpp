#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=3005;
char res[MAXN][MAXN];
int main()
{
    int m,n,s=0;
    scanf("%d%d",&m,&n);
    vector<int>a(m),b(m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]),s-=a[i];
    for(int i=0;i<m;i++)
        b[i]=2*(m-i-1);
    if(n<m)
    {
        for(int i=0;i<m;i++)
            s+=b[i];
        if(s<0)return 0*printf("no");
        for(int i=0;i<s;i++)
            a[i%(n-m)+n]++;
        if(a[n]>a[n-1])return 0*printf("no");
    }
    sort(a.begin(),a.end(),greater<int>());
    int ta=0,tb=0;
    for(int i=0;i<m;i++)
    {
        ta+=a[i],tb+=b[i];
        if(ta>tb)return 0*printf("no");
    }
    vector<pair<int,int> >v(m);
    for(int i=0;i<m;i++)
        v[i]=make_pair(a[i],i);
    const char ty[]="WDL";
    while(!v.empty())
    {
        sort(v.begin(),v.end());
        int t=(int)v.size(),p=v.back().second,cnt[3];
        res[p][p]='X';
        cnt[0]=v[t-1].first/2;
        cnt[1]=v[t-1].first%2;
        cnt[2]=t-1-cnt[0]-cnt[1];
        for(int i=0,k=0;i<3;k+=cnt[i++])
            for(int j=k;j<k+cnt[i];j++)
            {
                int q=v[j].second;
                v[j].first-=i;
                res[p][q]=ty[i];
                res[q][p]=ty[2-i];
            }
        v.pop_back();
    }
    printf("yes\n");
    for(int i=0;i<m;i++)
        printf("%s\n",res[i]);
    return 0;
}