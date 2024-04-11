#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN=50004;
char s[MAXN];
set<pair<ll,int> >st;
int main()
{
    scanf("%s",s);
    ll now=0,res=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='(')now++;
        else if(s[i]==')')now--;
        else
        {
            int a,b;
            scanf("%d%d",&a,&b);
            res+=b;
            s[i]=')';
            now--;
            st.insert(make_pair(a-b,i));
        }
        while(now<0)
        {
            if(st.empty())return 0*printf("-1");
            res+=st.begin()->first;
            s[st.begin()->second]='(';
            st.erase(st.begin());
            now+=2;
        }
    }
    if(now>0)printf("-1");
    else printf("%I64d\n%s",res,s);
    return 0;
}