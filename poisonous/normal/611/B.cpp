#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int main()
{
    long long a,b;
    cin>>a>>b;
    long long ans=0;
    for(int i=2;i<=62;i++)
        for(int j=0;j<i-1;j++)
        {
            long long x=(1ll<<i)-(1ll<<j)-1;
            if(x>=a&&x<=b)
                ans++;
        }
    cout<<ans;
}