#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<set>  
using namespace std;  

const int N = 100010;  
  
long long a[N],sum,s1[N];  

set<long long>s;  

int main()
{  
    int n;  
    scanf("%d",&n);  
    s1[0]=0;  
    for(int i=1;i<=n;i++)
	{  
        scanf("%lld",a+i);  
        sum+=a[i];  
        s1[i]=s1[i-1]+a[i];  
    }  
    bool ok=0;  
    s.clear();  
    for(int i=1;i<=n;i++)
	{  
        if(s.count(2*a[i]))
		{  
            ok=1;  
            break;  
        }  
        long long x=sum-2*s1[i];  
        if(x==0)
		{  
            ok=1;  
            break;  
        }  
        if(x>=0)  
            s.insert(x);  
    }  
    s.clear();  
    for(int i=n;i>=1;i--)
    {  
        if(s.count(2*a[i]))
        {  
            ok=1;  
            break;  
        }  
        long long x=2*s1[i]-sum;  
        if(x==0)
        {  
            ok=1;  
            break;  
        }  
        if(x>=0)  
            s.insert(x);  
    }  
    if(ok)  
        puts("YES");  
    else   
        puts("NO");  
}