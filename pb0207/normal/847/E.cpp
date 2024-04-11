#include<cstdio>
#include<iostream>
using namespace std;

const int N=1e5+1e3+7;

int n;

char s[N];

bool check(int m) 
{
    int last=0,right=0;
    for(int i=1;i<=n;i++) 
	{
        if(s[i]=='*') 
            if(right<i&&!last) 
				last=i;
        if(s[i]=='P') 
		{
            int pos=i;
            if(last&&pos-last>m) 
				return false;
            if(last) 
				pos=last;
            last=0;
            right=max(right,i);
            right=max(right,pos+(m-(i-pos)));
            right=max(right,i+(m-(i-pos))/2);
        }
    }
    return (last==0);
}

int main() 
{
    scanf("%d",&n);
    scanf("%s",s+1);
    int l=-1,r=2*n+1;
    while(r-l>1) 
	{
        int mid=(l+r)>>1;
        if(check(mid)) 
			r=mid;
        else 
			l=mid;
    }
    printf("%d\n",r);
    return 0;
}