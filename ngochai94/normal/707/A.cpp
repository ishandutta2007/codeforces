#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n,m;
bool ans;
char c;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m;
    ans=false;
    For(i,0,n) For(j,0,m)
    {
        cin>>c;
        if(c=='C'||c=='M'||c=='Y') ans=true;
    }
    if(ans) cout<<"#Color";
    else cout<<"#Black&White";
}