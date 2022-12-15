#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(long long i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.000001
#define pb push_back

int n;
pair<string,int> m[50004];
string lis[50004],s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n)
    {
        cin>>lis[i];
        s="";
        int tmp=lis[i].size();
        For(j,0,100) s+=lis[i][j%tmp];
        m[i]={s,i};
    }
    sort(m,m+n);
    s="";
    For(i,0,n)
    {
        int tmp=m[i].second;
        s+=lis[tmp];
    }

    cout<<s;
}