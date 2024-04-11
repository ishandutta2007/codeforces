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
char s[110];
const char h[]=" CODEFORCES";
int dp[110][15];
int main()
{
    cin>>(s+1);
    int i=strlen(s+1),n1,n2;
    if(i<10)
    {
        cout<<"NO";
        return 0;
    }
    for(n1=1;n1<=10;n1++)
        if(s[n1]!=h[n1])
            break;
    for(n2=10;n2>=1;n2--)
    {
        //cout<<s[i-9+n2]<<' '<<h[n2]<<endl;
        if(s[i-10+n2]!=h[n2])
            break;
        }
    if(n2<n1)
        cout<<"YES";
    else
        cout<<"NO";
}