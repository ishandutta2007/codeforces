#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
#include<stack>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
char s[110];
vector<int>g1,g2,g3;
int main()
{
    int T;scanf("%d",&T);
    for(;T--;)
    {
        scanf("%s",s+1);
        g1.clear();g2.clear();g3.clear();
        bool f1=0,f2=0,f3=0;
        int n=strlen(s+1);
        rep(i,n)
        {
            if('0'<=s[i]&&s[i]<='9')f1=1,g1.pb(i);
            if('a'<=s[i]&&s[i]<='z')f2=1,g2.pb(i);
            if('A'<=s[i]&&s[i]<='Z')f3=1,g3.pb(i);
        }
        if(!f1&&!f2)s[1]='0',s[2]='a';
        else if(!f1&&!f3)s[1]='0',s[2]='A';
        else if(!f2&&!f3)s[1]='a',s[2]='A';
        else if(!f1)
        {
            if(g2.size()>1)s[g2[0]]='0';
            else s[g3[0]]='0';
        }
        else if(!f2)
        {
            if(g1.size()>1)s[g1[0]]='a';
            else s[g3[0]]='a';
        }
        else if(!f3)
        {
            if(g2.size()>1)s[g2[0]]='A';
            else s[g1[0]]='A';
        }
        puts(s+1);
    } 
	return 0;
}