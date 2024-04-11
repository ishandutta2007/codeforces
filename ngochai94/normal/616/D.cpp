#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back
#define off 600000

int lis[500005],n,k,l,r,cnt,cur[1000006],ansl,ansr;

int main(){
    //freopen("input.txt","r",stdin);
    //ios::sync_with_stdio(0);
    scanf("%d %d",&n,&k);
    For(i,0,n) scanf("%d",&lis[i]);
    ansl=ansr=0;
    l=r=0;
    cnt=1;
    cur[lis[0]]=1;
    while(++r<n)
    {
        if(!cur[lis[r]]) cnt++;
        cur[lis[r]]++;
        //cout<<111<<endl;
        if(cnt>k)
        {
            cnt--;
            cur[lis[r]]=0;
            r--;
            break;
        }
    }
    ansr=min(r,n-1);
    //printf("%d\n",l);
    while(++r<n)
    {
        //printf("%d\n",cnt);
        if(!cur[lis[r]]) cnt++;
        cur[lis[r]]++;
        //printf("%d\n",r);
        while(cnt>k)
        {
            //printf("%d\n",l);
            cur[lis[l]]--;
            //printf("curlis: %d\n",cur[lis[l]]);
            if(!cur[lis[l]]) cnt--;
            l++;
        }
        //printf("%d\n",r);
        if(ansr-ansl<r-l)
        {
            ansr=r;
            ansl=l;
        }
        //printf("%d %d\n",l,r);
    }
    printf("%d %d",ansl+1,ansr+1);
}