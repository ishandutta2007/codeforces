#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n, cur;
string s;
vector<int> ans;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> s;
    for (char c: s)
    {
        if (c == 'B')
        {
            cur++;
        }
        else
        {
            if(cur)
            {
                ans.pb(cur);
            }
            cur = 0;
        }
    }
    if(cur) ans.pb(cur);
    cout << ans.size() << endl;
    for(int i: ans) cout << i << ' ';
}