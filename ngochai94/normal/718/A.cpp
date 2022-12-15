#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 10007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n, t, poi;
string s;
int flag;
bool append1;

void f()
{
    int ind=poi-1;
    while(ind>=0)
    {
        if(s[ind]=='9')
        {
            s[ind]='0';
            ind--;
        }
        else
        {
            s[ind]++;
            For(i,0,poi) cout<<s[i];
            return;
        }
    }
    cout<<1;
    For(i,0,poi) cout<<s[i];
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>t>>s;
    For(i,0,n) if(s[i] == '.')
    {
        poi = i;
        break;
    }
    flag = 0;
    For(i,poi+1,n) if(s[i]>='5')
    {
        int j = i;
        while(t && s[j]!='.' && s[j]>='5')
        {
            t--;
            j--;
            while(s[j]=='9')
            {
                s[j]='0';
                j--;
            }
            if(s[j]=='.')
            {
                f();
                return 0;
            }
            s[j]++;
        }
        For(i,0,j+1) cout<<s[i];
        return 0;
    }
    For(i,0,n) cout<<s[i];
}