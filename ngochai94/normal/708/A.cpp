#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

string s;
bool flag;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    flag=false;
    cin>>s;
    For(i,0,s.size())
    {
        if(s[i]!='a')
        {
            flag=true;
            For(j,i,s.size())
            {
                if(s[j]=='a') break;
                s[j]--;
            }
            break;
        }
    }
    if(!flag) s[s.size()-1]='z';
    cout<<s;
}