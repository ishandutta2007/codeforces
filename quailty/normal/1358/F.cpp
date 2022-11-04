#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll A[MAXN],B[MAXN];
void solve_1()
{
    if(A[1]==B[1])printf("SMALL\n0\n");
    else printf("IMPOSSIBLE\n");
}
void solve_2()
{
    bool isok=1;
    ll mi=min(A[1],A[2]),cnt_p=0;
    string res;
    while(1)
    {
        if(A[1]==B[1] && A[2]==B[2])
            break;
        if(A[1]==B[2] && A[2]==B[1])
        {
            if(cnt_p<=200000)
                res+='R';
            break;
        }
        if(B[1]<B[2])
        {
            ll t;
            if(min(B[1],B[2])>mi)
                t=(B[2]-1)/B[1];
            else
                t=(B[2]-A[1]-A[2]+mi)/B[1];
            if(t<=0)
            {
                isok=0;
                break;
            }
            B[2]-=t*B[1];
            if((cnt_p+=t)<=200000)
                res+=string(t,'P');
        }
        else if(B[1]>B[2])
        {
            swap(B[1],B[2]);
            if(cnt_p<=200000)
                res+='R';
        }
        else
        {
            isok=0;
            break;
        }
    }
    if(!isok)printf("IMPOSSIBLE\n");
    else
    {
        reverse(res.begin(),res.end());
        if(cnt_p>200000)printf("BIG\n%lld\n",cnt_p);
        else printf("SMALL\n%zu\n%s\n",res.size(),res.c_str());
    }
}
void solve_3(int n)
{
    bool isok=1;
    int cnt_p=0;
    string res;
    while(1)
    {
        bool match=1;
        for(int i=1;i<=n;i++)
            match&=(A[i]==B[i]);
        if(match)break;
        match=1;
        for(int i=1;i<=n;i++)
            match&=(A[i]==B[n+1-i]);
        if(match)
        {
            if(cnt_p<=200000)
                res+='R';
            break;
        }
        bool u=1,d=1;
        for(int i=1;i<n;i++)
        {
            u&=(B[i]<B[i+1]);
            d&=(B[i]>B[i+1]);
        }
        if(u)
        {
            for(int i=n;i>1;i--)
                B[i]-=B[i-1];
            if(++cnt_p<=200000)
                res+='P';
        }
        else if(d)
        {
            reverse(B+1,B+n+1);
            if(cnt_p<=200000)
                res+='R';
        }
        else
        {
            isok=0;
            break;
        }
    }
    if(!isok)printf("IMPOSSIBLE\n");
    else
    {
        reverse(res.begin(),res.end());
        if(cnt_p>200000)printf("BIG\n%d\n",cnt_p);
        else printf("SMALL\n%zu\n%s\n",res.size(),res.c_str());
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&A[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&B[i]);
    if(n==1)solve_1();
    else if(n==2)solve_2();
    else solve_3(n);
    return 0;
}