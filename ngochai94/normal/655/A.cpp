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
string s1,s2,s;

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>s1>>s;
    s1+=s[1];
    s1+=s[0];
    cin>>s2>>s;
    s2+=s[1];
    s2+=s[0];
    For(i,0,3) if(s1[i]=='X') swap(s1[i],s1[i+1]);
    s1=s1.substr(0,3);
    if(s1=="ABC"||s1=="BCA"||s1=="CAB") s1="ABC";
    else s1="ACB";
    For(i,0,3) if(s2[i]=='X') swap(s2[i],s2[i+1]);
    s2=s2.substr(0,3);
    if(s2=="ABC"||s2=="BCA"||s2=="CAB") s2="ABC";
    else s2="ACB";
    //cout<<s1<<' '<<s2<<endl;
    if(s1==s2) cout<<"YES";
    else cout<<"NO";
}