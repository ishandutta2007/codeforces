#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n, lis[111];
string s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n) scanf("%d ", &lis[i]);
    //scanf("\n\n");
    For(i,0,n)
    {
        //cout << i;
        getline(cin, s);
        //cout<<s;
        int cur=0;
        for(char c:s) if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y') cur++;
        if(cur!=lis[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout <<"YES";
}