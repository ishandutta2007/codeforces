#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n, k, ansmin, ansmax;
string s;
vector<int> v;

int get(int x)
{
    //cout << x << endl;
    if(x&&(x%k==0)) return 6;
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    while(n--)
    {
        cin>>s;
        v.pb(s.size());
    }
    cin>>s;
    int ans = s.size();
    sort(v.begin(), v.end());
    bool flag = false;
    For(i,0,v.size())
    {
        if(v[i]==ans)
        {
            if (!flag)
            {
                flag = true;
                ansmin+=get(i);
                ansmax=ansmin;
                continue;
            }
            ansmax+=get(i);
        }
        else if(v[i]<ans)
        {
            ansmin+=get(i);
            //cout<<ansmin<<endl;
        }
        else if (v[i]>ans) break;
    }
    cout << ansmin << ' ' << ansmax;
}