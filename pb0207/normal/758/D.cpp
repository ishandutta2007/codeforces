#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
#define N 20020  
#define inf 1LL<<60  
using namespace std;  
typedef long long ll;  
ll n,m,num[N],tot,pw[N],ans,pw10[N];  
char ch[66];  
void solve()  
{  
    ll now=0,next,nexp,cnt=0;  
    pw10[0]=1;bool f=0;  
    for(int i=1;i<20;i++)pw10[i]=pw10[i-1]*10;  
    for(int i=m;i>0;i=nexp)  
    {  
        ll j,nu;  
        if(ch[i]!='0')  
        {  
            next=now+(ll)(ch[i]-'0')*pw10[cnt];  
            nexp=i-1;  
        }  
        else  
        {  
            j=i,nu=0;  
            while(ch[j]=='0'&&j)j--,nu++;  
            if(nu>10)next=inf;  
            else if(!j)next=now,nexp=j;  
            else   
            {  
                next=(ch[j]-'0')*pw10[nu+cnt]+now;  
                nexp=j-1,cnt+=nu;  
            }  
        }  
        if(next>=n)  
        {  
            if(now||i!=m)num[++tot]=now;  
            now=ch[i]-'0',cnt=1;  
            nexp=i-1;
        }else   
        {  
              
            now=next,cnt++;if(ch[i]!='0')nexp=i-1;  
        }  
    }  
    num[++tot]=now;  
    pw[1]=1;  
    for(int i=2;i<=tot;i++)pw[i]=pw[i-1]*n;  
    for(int i=1;i<=tot;i++)  
        ans+=num[i]*pw[i];  
    printf("%I64d\n",ans);  
}  
int main()  
{    
    scanf("%I64d",&n);  
    scanf("%s",ch+1);  
    m=strlen(ch+1);  
    solve();  
}