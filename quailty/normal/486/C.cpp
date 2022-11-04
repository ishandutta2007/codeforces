#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[100005];
vector<int>loc;
int main()
{
    int n,p,res=0;
    scanf("%d%d%s",&n,&p,s+1);
    for(int i=1,j=n;i<=j;i++,j--)
        if(s[i]!=s[j])
        {
            res+=min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
            loc.push_back(i);
        }
    if(loc.empty())return 0*printf("0");
    int mi=loc[0],mx=loc[(int)loc.size()-1],tmp;
    if(p<mi)tmp=mx-p;
    else if(p>mx)tmp=p-mi;
    else tmp=mx-mi+min(mx-p,p-mi);
    mi=n+1-loc[(int)loc.size()-1],mx=n+1-loc[0];
    if(p<mi)tmp=min(tmp,mx-p);
    else if(p>mx)tmp=min(tmp,p-mi);
    else tmp=min(tmp,mx-mi+min(mx-p,p-mi));
    return 0*printf("%d",res+tmp);
}