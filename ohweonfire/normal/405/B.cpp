#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
char ch[3005];
int n;
inline bool check(int &x,int&y,int&i)
{
     if(ch[i]!='.')return false;
     if(x<0&&y>=n)return true;
     if(x<0)if(ch[y]=='R')return true;else return false;
     if(y>=n)if(ch[x]=='R')return false;else return true;
     if(ch[x]=='L'&&ch[y]=='R')return true;
     if(ch[x]=='R'&&ch[y]=='L'&&i-x==y-i)return true;
     return false;
}
int main()
{
    
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>ch[i];
    for(int i=0;i<n;i++)
    {
            int k1=i-1,k2=i+1;
            while(k1>=0&&ch[k1]=='.')k1--;
            while(k2<n&&ch[k2]=='.')k2++;
            if(check(k1,k2,i))ans++;
    }
    cout<<ans<<endl;
    return 0;
}