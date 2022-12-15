#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 10007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

string s;
int x,y;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s;
    for(char c:s)
    {
        if(c=='U') y++;
        else if(c=='D') y--;
        else if(c=='L') x--;
        else x++;
    }
    if(s.size()%2) cout<< -1;
    else cout<<(abs(x)+abs(y))/2;
}