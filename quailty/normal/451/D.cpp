#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
char s[MAXN];
int main()
{
    scanf("%s",s);
    ll cnt[2][2]={0},res[2]={0};
    for(int i=0;s[i];i++)
    {
        for(int j=0;j<2;j++)
            swap(cnt[j][0],cnt[j][1]);
        cnt[s[i]-'a'][1]++;
        for(int j=0;j<2;j++)
            res[j]+=cnt[s[i]-'a'][j];
    }
    return 0*printf("%lld %lld",res[0],res[1]);
}