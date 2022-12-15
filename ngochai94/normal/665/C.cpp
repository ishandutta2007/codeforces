#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n;
string s;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s;
    n = s.size();
    For(i,1,n)
    {
        if(s[i]==s[i-1])
        {
            char a = s[i-1];
            char b = a;
            if(i!=n-1) b = s[i+1];
            if(a!='a'&&b!='a') s[i]='a';
            else if(a!='b'&&b!='b') s[i]='b';
            else s[i]='c';
        }
    }
    cout<<s;
}